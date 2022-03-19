#lang racket/base
(define (f a b)
  ((if (> b 0) + -) a b))

(f 1 2)

(f 1 -2)