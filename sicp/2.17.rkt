#lang racket/base
(define (last-pair i)
  (if (null? (cdr i))
      (car i)
      (last-pair (cdr i))))

(last-pair (list 23 72 149 34))