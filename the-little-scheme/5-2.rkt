#lang racket

(define (atom? x)
  (and (not (pair? x)) (not (null? x))))

(define (leftmost l)
  (cond
    ((atom? (car l))
     (car l))
    (else
     (leftmost (car l)))))

(leftmost '(((1)) 1 (1 2) 3))