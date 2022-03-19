#lang racket/base

(require "3.50.rkt")
(require "3.53.rkt")

(define (integral delayed-integrand initial-value dt)
  (define int
    (cons-stream initial-value
     (let ((integrand (force delayed-integrand)))
       (add-streams (scale-stream integrand dt) int))))
  int)

(define (solve-2nd a b dt y0 dy0)
  (define y (integral (delay dy) y0 dt))
  (define dy (integral (delay ddy) dy0 dt))
  (define ddy (add-streams
               (scale-stream dy a)
               (scale-stream y b)))
  y)

;;;;;;;;;;;;;;;;;
; ddy + 2 * dy + y = 0
; y(0) = 4, dy(0) = -2
(displayln "solve-2nd")
(stream-ref (solve-2nd -2 -1 0.001 4 -2) 20)

; 特解为 y = (4 + 2t) * exp(-t)
; 直接打印出方程值作对比
(define (solution t)
  (* (+ 4 (* 2 t)) (exp (- t))))
(define (solution-steam t dt)
  (cons-stream (solution t) (solution-steam (+ t dt) dt)))
(displayln "solution")
(stream-ref (solution-steam 0 0.001) 20)