#lang racket/base

(require "3.50.rkt")
(require "3.53.rkt")

(define (rand-update x)
  (let ((a 48271) (b 19851020) (m 2147483647))
    (modulo (+ (* a x) b) m)))

(define random-init-1 7)
(define random-init-2 17)

(define (random-numbers random-init)
  (define inner-stream
    (cons-stream random-init
               (stream-map rand-update 
                           inner-stream)))
  inner-stream)

(define (monte-carlo experiment-stream 
                     passed 
                     failed)
  (define (next passed failed)
    (cons-stream
     (/ passed (+ passed failed))
     (monte-carlo
      (stream-cdr experiment-stream) 
      passed 
      failed)))
  (if (stream-car experiment-stream)
      (next (+ passed 1) failed)
      (next passed (+ failed 1))))

(define (random-in-range low high random-init)
  (let ((max 1000000)
        (range (- high low)))
    (stream-map ;; low ~ range
     (lambda (u) (+ low (* u range)))
     (stream-map (lambda (v) ;; 0 ~ 1
                   (/ (remainder v max) max))
                 (random-numbers random-init)))))

(define (map-stream-pairs f s t)
  (cons-stream
   (f (stream-car s) 
      (stream-car t))
   (map-stream-pairs f (stream-cdr s) (stream-cdr t))))

(define (estimate-integral f x1 x2 y1 y2)
  (let ((area (* (abs (- x2 x1))
                 (abs (- y2 y1)))))
    (scale-stream
     (monte-carlo
      (map-stream-pairs f
                            (random-in-range x1 x2 random-init-1)
                            (random-in-range y1 y2 random-init-2))
      0 0)
     area)))

(define (estimate-pi)
  (define (inside-circle? x y)
    (define (square x) (* x x))
    (< (+ (square x) (square y)) 1.0))
  (estimate-integral inside-circle? -1 1 -1 1))

(exact->inexact (stream-ref (estimate-pi) 10000))