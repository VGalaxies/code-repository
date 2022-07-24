#lang racket/base
(define (inc n) (+ n 1))

(define (square x) (* x x))

(define (identity x) x)

;let null-value be the operand when the filter return #f
(define (filtered-accumulate filter combiner null-value term a next b)
  (cond ((> a b) null-value)
        ((filter a)
         (combiner (term a)
                (filtered-accumulate filter combiner null-value term (next a) next b)))
        (combiner null-value
                (filtered-accumulate filter combiner null-value term (next a) next b))))

(define (smallest-divisor n)
  (find-divisor n 2))

(define (find-divisor n test-divisor)
  (cond ((> (square test-divisor) n) 
         n)
        ((divides? test-divisor n) 
         test-divisor)
        (else (find-divisor 
               n 
               (+ test-divisor 1)))))

(define (divides? a b)
  (= (remainder b a) 0))

(define (prime? n)
  (= n (smallest-divisor n)))

(define (sum-primes a b)
  (filtered-accumulate prime? + 0 identity a inc b))

(sum-primes 2 20)

(define (product-primes n)
  (filtered-accumulate prime? * 1 identity 2 inc n))

(product-primes 10)