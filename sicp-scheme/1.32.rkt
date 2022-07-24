#lang racket/base
(define (inc n) (+ n 1))

(define (cube x) (* x x x))

(define (identity x) x)

(define (accumulate combiner null-value term a next b)
  (if (> a b)
      null-value
      (combiner (term a)
                (accumulate combiner null-value term (next a) next b))))

(define (product-gen term a next b)
  (accumulate * 1 term a next b))

(define (factorial n)
  (product-gen identity 1 inc n))

(factorial 3)

(define (sum-gen term a next b)
  (accumulate + 0 term a next b))

(define (sum-cubes a b)
  (sum-gen cube a inc b))

(sum-cubes 1 10)


;iter
(define (accumulate-iter combiner null-value term a next b)
  (define (iter combiner a result)
    (if (> a b)
        result
        (iter combiner (next a) (combiner (term a) result))))
  (iter combiner a null-value))

(define (product-gen-iter term a next b)
  (accumulate-iter * 1 term a next b))

(define (factorial-iter n)
  (product-gen-iter identity 1 inc n))

(factorial-iter 4)