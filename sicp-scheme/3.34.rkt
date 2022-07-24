#lang racket/base

(require "./3.33.rkt")

(define (squarer a b) (multiplier a a b))

;;;;;;;;;;;;;;;;;;;;;;;;;;;

(define a (make-connector))
(define b (make-connector))

(squarer a b)

(probe "a" a)
(probe "b" b)

(set-value! a -1 'user)

(forget-value! a 'user)
(set-value! b 8 'user)