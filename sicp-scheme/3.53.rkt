#lang racket/base

(require "3.50.rkt")

(provide add-streams integers-starting-from integers scale-stream)
(provide stream-head->list)

;;;;;;;;;;;;;;;;;;;;;;;;;;

(define (divisible? x y) (= (remainder x y) 0))
(define (square x) (* x x))

;;;;;;;;;;;;;;;;;;;;;;;;;;

;; 将 s 的前 n 个值转成列表方便调试
(define (stream-head->list s n)
  (if (or (= n 0) (stream-null? s))
      '()
      (cons (stream-car s) (stream-head->list (stream-cdr s) (- n 1)))))

;;;;;;;;;;;;;;;;;;;;;;;;;;

(define (integers-starting-from n)
  (cons-stream n (integers-starting-from (+ n 1))))

(define integers (integers-starting-from 1))

(define (fibgen a b)
  (cons-stream a (fibgen b (+ a b))))

(define fibs (fibgen 0 1))

(define (sieve stream)
  (cons-stream
    (stream-car stream)
    (sieve (stream-filter
             (lambda (x)
               (not (divisible? x (stream-car stream))))
             (stream-cdr stream)))))

(define primes (sieve (integers-starting-from 2)))

;; 隐式地定义流
(define ones (cons-stream 1 ones))

(define (add-streams s1 s2)
  (stream-map + s1 s2))

(define integers-2 (cons-stream 1 (add-streams ones integers-2)))

(define fibs-2 
  (cons-stream 0
               (cons-stream 1
                            (add-streams (stream-cdr fibs) 
                                         fibs))))

(define (scale-stream stream factor)
  (stream-map (lambda (x) (* x factor)) stream))

(define primes-2
  (cons-stream 2 (stream-filter prime? (integers-starting-from 3))))

(define (prime? n)
  (define (iter ps)
    (cond ((> (square (stream-car ps)) n) #t)
          ((divisible? n (stream-car ps)) #f)
          (else (iter (stream-cdr ps)))))
  (iter primes-2))

;;;;;;;;;;;;;;;;;;;;

(define double (cons-stream 1 (scale-stream double 2)))
(define double-2 (cons-stream 1 (add-streams double-2 double-2)))