#lang racket/base
(define (double x) (* x 2))

(define (halve x) (/ x 2))

(define (aid a b p)
  (cond ((= b 0) p)
        ((even? b) (aid (double a) (halve b) p))
        (else (aid a (- b 1) (+ p a)))))

(define (mul a b)
  (aid a b 0))

(mul 2 9)