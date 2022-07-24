#lang racket/base

(require "3.50.rkt")
(require "3.53.rkt")
(require "3.59.rkt")
(require "3.60.rkt")
(provide invert-unit-series)

(define (invert-unit-series s)
  (cons-stream 1
               (sub-streams zeros
                            (mul-series (stream-cdr s)
                                        (invert-unit-series s)))))

(module* main #f
  (define S (invert-unit-series exp-series))
  (stream-head->list S 10)
)