#lang racket/base
(define (element-of-set? x set)
  (cond ((null? set) #f)
        ((equal? x (car set)) #t)
        (else (element-of-set? x (cdr set)))))

(define (adjoin-set x set)
  (cons x set))

(define (intersection-set set1 set2)
  (cond ((or (null? set1) (null? set2)) '())
        ((element-of-set? (car set1) set2)
         (cons (car set1)
               (intersection-set (cdr set1) set2)))
        (else (intersection-set (cdr set1) set2))))

(define (union-set set1 set2)
  (append set1 set2))

;;;;;;;;;;;;;;;;;;;;;;;;;;;
(define a '(1 2 2 3 4 4 5 6))
(define b '(4 4 5 6 7 8 9))

(element-of-set? 10 a)  ; #f
(element-of-set? 9 b)   ; #t

(adjoin-set 10 a)       ; '(10 1 2 2 3 4 4 5 6)
(intersection-set a b)  ; '(4 4 5 6)
(union-set a b)         ; '(1 2 2 3 4 4 5 6 4 4 5 6 7 8 9)