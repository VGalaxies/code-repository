#lang racket/base
(define (C m n)
  (cond ((= m n) 1)
        ((= m 1) n)
        (else (+ (C m (- n 1))
                 (C (- m 1) (- n 1))))))

(C 3 5)