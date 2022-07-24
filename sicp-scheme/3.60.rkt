#lang racket/base

(require "3.50.rkt")
(require "3.53.rkt")
(require "3.59.rkt")
(provide mul-series)

(define add-series add-streams)

(define (mul-series s1 s2)
  (cons-stream
    (* (stream-car s1) (stream-car s2))
    (add-streams (add-streams (scale-stream (stream-cdr s1) (stream-car s2))
                              (scale-stream (stream-cdr s2) (stream-car s1)))
                 (cons-stream 0 (mul-series (stream-cdr s1) (stream-cdr s2))))))


(module* main #f
  (define S (add-series (mul-series cosine-series cosine-series)
                      (mul-series sine-series sine-series)))
  (stream-head->list S 10)
)