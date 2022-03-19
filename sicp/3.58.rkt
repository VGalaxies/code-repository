#lang racket/base

(require "3.50.rkt")
(require "3.53.rkt")

(define (expand num den radix)
  (cons-stream
   (quotient (* num radix) den)
   (expand (remainder (* num radix) den) 
           den 
           radix)))

(define S (expand 1 7 10))

(define T (expand 3 8 10))

(stream-head->list S 10)

(stream-head->list T 10)