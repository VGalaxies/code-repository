#lang racket/base
(require "3.50.rkt")

;;;;;;;;;;;;;;;;;;;;;
(define (show x)
  (display-line x)
  x)

(define x (stream-map show (stream-enumerate-interval 0 10)))
(newline)
(stream-ref x 5)
(newline)
(stream-ref x 7)