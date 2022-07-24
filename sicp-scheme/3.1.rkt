#lang racket/base
(define (make-accumulator sum)
 (lambda (now)
   (begin (set! sum (+ sum now))
          sum)))

(define A (make-accumulator 5))

(A 10)`

(A 10)