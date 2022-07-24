#lang racket/base
(define (double x) (* x 2))

(define (halve x) (/ x 2))

(define (mul a b)
  (cond((= b 1) a)
       ((even? b)
        (* (double a) (halve b)))
       (else (+ a (mul a (- b 1))))))

(mul 7 89)


