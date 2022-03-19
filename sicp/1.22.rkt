#lang racket/base
(define (runtime) (current-inexact-milliseconds))

(define (timed-prime-test n)
  (newline)
  (display n)
  (start-prime-test n (runtime)))

;https://stackoverflow.com/questions/10863192/why-is-one-armed-if-missing-from-racket

(define (start-prime-test n start-time)
  (when (prime? n)
      (report-prime (- (runtime) 
                       start-time))))

(define (report-prime elapsed-time)
  (display " *** ")
  (display elapsed-time))

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

(timed-prime-test 199)
(timed-prime-test 19999)

(define (search-for-primes st ed)
  (when (< st ed)
      (timed-prime-test st)
      (search-for-primes (+ st 1) ed)))

(search-for-primes 10000 10100)