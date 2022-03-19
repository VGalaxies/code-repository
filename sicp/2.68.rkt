#lang racket/base
(define (make-leaf symbol weight)
  (list 'leaf symbol weight))

(define (leaf? object)
  (eq? (car object) 'leaf))

(define (symbol-leaf x)
  (cadr x))

(define (weight-leaf x)
  (caddr x))

(define (make-code-tree left right)
  (list left
        right
        (append (symbol left) (symbol right))
        (+ (weight left) (weight right))))

(define (left-branch tree)
  (car tree))

(define (right-branch tree)
  (cadr tree))

(define (symbol tree)
  (if (leaf? tree)
      (list (symbol-leaf tree))
      (caddr tree)))

(define (weight tree)
  (if (leaf? tree)
      (weight-leaf tree)
      (cadddr tree)))

(define (encode message tree)
  (if (null? message)
      '()
      (append 
       (encode-symbol (car message) 
                      tree)
       (encode (cdr message) tree))))

(define (encode-symbol sym tree)
  (define (element-of-set? x set)
    (cond ((null? set) #f)
          ((equal? x (car set)) #t)
          (else (element-of-set? x (cdr set)))))
  (define (encode-symbol-1 result current-branch)
    (cond
      ((leaf? current-branch) result)
      ((element-of-set? sym (symbol (left-branch current-branch)))
       (encode-symbol-1 (append result (list 0)) (left-branch current-branch)))
      ((element-of-set? sym (symbol (right-branch current-branch)))
       (encode-symbol-1 (append result (list 1)) (right-branch current-branch)))
      (else
       (error "no such symbol" sym))))
  (encode-symbol-1 '() tree))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(define sample-tree
  (make-code-tree (make-leaf 'A 4)
                  (make-code-tree (make-leaf 'B 2)
                                  (make-code-tree (make-leaf 'D 1)
                                                  (make-leaf 'C 1)))))

(define sample-symbol '(A D A B B C A))

(encode sample-symbol sample-tree)