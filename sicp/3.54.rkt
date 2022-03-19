#lang racket/base

(require "3.50.rkt")
(require "3.53.rkt")

(define (mul-streams s1 s2)
  (stream-map * s1 s2))

(define factorials 
  (cons-stream 1 (mul-streams factorials (integers-starting-from 2))))

;;;;;;;;;;;;;;;;;;;

(stream-head->list factorials 10)