#lang racket/base
(define (runtime) (current-inexact-milliseconds))

(define (square x) (* x x))

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

(define (make_odd x)
  (if (odd? x)
      (+ x 2)
      (+ x 1)))

(define (continue-primes n count)
    (cond ((= count 0)
            (display "are primes.")
            (newline))
          ((prime? n)
            (display n)
            (newline)
            (continue-primes (make_odd n) (- count 1)))
          (else
            (continue-primes (make_odd n) count))))

(define (search-for-primes n count)
    (let ((start-time (runtime)))
        (continue-primes n count)
        (- (runtime) start-time)))

(search-for-primes 1000 100)

