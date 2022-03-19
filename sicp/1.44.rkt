#lang racket/base
(define dx 0.1)

(define (smooth f)
  (lambda (x)
    (/ (+ (f (- x dx))
          (f x)
          (f (+ x dx)))
       3)))

(define (square x) (* x x))

((smooth square) 3)

(define (compose f g)
  (lambda (x) (f (g x))))

(define (repeated f n)
  (if (= n 0)
      (lambda (x) x)
      (lambda (x) ((compose f (repeated f (- n 1))) x))))

(define (smooth-repeat f n)
  ((repeated smooth n) f))

((smooth-repeat square 10) 3)