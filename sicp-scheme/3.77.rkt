#lang racket/base

(require "3.50.rkt")
(require "3.53.rkt")

(define (integral delayed-integrand initial-value dt)
  (define int
    (cons-stream initial-value
     (let ((integrand (force delayed-integrand)))
       (add-streams (scale-stream integrand dt) int))))
  int)

(define (solve f y0 dt)
  (define y (integral (delay dy) y0 dt))
  (define dy (stream-map f y))
  y)

(stream-ref (solve (lambda (y) y) 1 0.001) 1000)

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(define (integral-2 delayed-integrand initial-value dt)
  (cons-stream initial-value
               (let ((integrand (force delayed-integrand)))
                 (if (stream-null? integrand)
                     the-empty-stream
                     (integral-2 (delay (stream-cdr integrand)) ;; 此处勿忘delay
                                 (+ (* dt (stream-car integrand))
                                    initial-value)
                                 dt)))))

(define (solve-2 f y0 dt)
  (define y (integral-2 (delay dy) y0 dt))
  (define dy (stream-map f y))
  y)

(stream-ref (solve-2 (lambda (y) y) 1 0.001) 1000)