#lang racket/base

(require "3.50.rkt")
(require "3.53.rkt")
(require "3.59.rkt")
(require "3.60.rkt")
(require "3.61.rkt")

(define (div-series s1 s2)
  (define normalizer (cons-stream (stream-car s2) normalizer))
  (if (= (stream-car s2) 0)
      (error "constant term of s2 can't be 0 -- DIV-SERIES")
      (mul-series (div-streams s1 normalizer)
                  (invert-unit-series (div-streams s2 normalizer)))))


(define tan-series (div-series sine-series cosine-series))
(stream-head->list tan-series 10)