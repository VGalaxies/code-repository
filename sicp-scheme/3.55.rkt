#lang racket/base

(require "3.50.rkt")
(require "3.53.rkt")

(define (partial-sums stream)
  (cons-stream (stream-car stream)
               (add-streams (stream-cdr stream) (partial-sums stream))))

;;;;;;;;;;;;;;;;;;;;;;;

(stream-head->list (partial-sums integers) 10)