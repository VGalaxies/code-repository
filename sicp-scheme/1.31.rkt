#lang racket/base
(define (inc n) (+ n 1))

(define (inc-inc n) (+ n 2))

(define (square x) (* x x))

(define (identity x) x)

(define (product term a next b)
  (if (> a b)
      1
      (* (term a)
         (product term (next a) next b))))

(define (factorial n)
  (product identity 1 inc n))

(factorial 4)

(define (pi n)
  (define (aid st n)
     (product identity st inc-inc n))
  (/ (* (/ (square (aid 2 n)) (square (aid 3 n)))
     2.0)
     n))

;n must be even
(pi 1000)


(define (product-iter term a next b)
  (define (iter a result)
    (if (> a b)
        result
        (iter (next a) (* (term a) result))))
  (iter a 1))

(define (factorial-iter n)
  (product-iter identity 1 inc n))

(factorial-iter 4)