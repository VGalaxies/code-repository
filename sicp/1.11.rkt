#lang racket/base
(define (fib n) 
  (fib-iter 3 2 1 n))

(define (fib-iter a b c count)
  (if (= count 1)
      c
      (fib-iter (+ a
                   (* 2 b)
                   (* 3 c)) a b (- count 1))))

(fib 5)