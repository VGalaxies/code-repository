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

(define (decode bits tree)
  (define (decode-1 bits current-branch)
    (if (null? bits)
        null 
        (let ((next-branch (choose-branch (car bits) current-branch)))
          (if (leaf? next-branch)
              (cons (symbol-leaf next-branch)
                    (decode-1 (cdr bits) tree))
              (decode-1 (cdr bits) next-branch)))))
  (decode-1 bits tree))

(define (choose-branch bit branch)
  (cond ((= bit 0) (left-branch branch))
        ((= bit 1) (right-branch branch))
        (else (error "bad bit -- CHOOSE-BRANCH" bit))))

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

(define (adjoin-set x set)
  (cond ((null? set) (list x))
        ((< (weight x) (weight (car set))) 
         (cons x set))
        (else 
         (cons (car set)
               (adjoin-set x (cdr set))))))

(define (make-leaf-set pairs)
  (if (null? pairs)
      '()
      (let ((pair (car pairs)))
        (adjoin-set 
         (make-leaf (car pair)    ; symbol
                    (cadr pair))  ; frequency
         (make-leaf-set (cdr pairs))))))

(define (generate-huffman-tree pairs)
  (successive-merge 
   (make-leaf-set pairs)))

(define (successive-merge now)
  (if (= (length now) 1)
      (car now)
      (successive-merge
       (adjoin-set (make-code-tree (car now)
                                   (cadr now))
                   (cddr now)))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(define huffman-tree (generate-huffman-tree '((A 4) (B 2) (C 1) (D 1))))
(define symbols '(A D A B B C A))
(define message (encode symbols huffman-tree))

huffman-tree                  ; '((leaf A 4) ((leaf B 2) ((leaf D 1) (leaf C 1) (D C) 2) (B D C) 4) (A B D C) 8)
symbols                       ; '(A D A B B C A)
message                       ; '(0 1 1 0 0 1 0 1 0 1 1 1 0)
(decode message huffman-tree) ; '(A D A B B C A)