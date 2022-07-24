#lang racket/base
(define (f g) (g 2))

(define (square x) (* x x))

(f f)