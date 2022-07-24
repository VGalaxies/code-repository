#lang racket/base
(define (square x) (* x x))

(define (sum-of-squares x y)
    (+ (square x) 
       (square y)))

(define (bigger a b)
  (if (> a b)
      a
      b))

(define (smaller a b)
  (if (< a b)
      a
      b))

(define (max a b c)
  (sum-of-squares (bigger a b)
                  (bigger (smaller a b) c)))

(max 3 5 7)