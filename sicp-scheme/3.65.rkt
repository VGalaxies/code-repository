#lang racket/base

(require "3.50.rkt")
(require "3.53.rkt")

(define (partial-sums stream)
  (cons-stream (stream-car stream)
               (add-streams (stream-cdr stream) (partial-sums stream))))

(define (square x) (* x x))

(define (ln2-summands n)
  (cons-stream 
   (/ 1.0 n)
   (stream-map - (ln2-summands (+ n 1)))))

(define ln2-stream
  (partial-sums (ln2-summands 1)))

(define (euler-transform s)
  (let ((s0 (stream-ref s 0))     ; Sn-1
        (s1 (stream-ref s 1))     ; Sn
        (s2 (stream-ref s 2)))    ; Sn+1
    (cons-stream 
     (- s2 (/ (square (- s2 s1))
              (+ s0 (* -2 s1) s2)))
     (euler-transform (stream-cdr s)))))

(define (make-tableau transform s)
  (cons-stream 
   s
   (make-tableau
    transform
    (transform s))))

(define (accelerated-sequence transform s)
  (stream-map stream-car
              (make-tableau transform s)))

(stream-head->list ln2-stream 10)
(stream-head->list (euler-transform ln2-stream) 10)
(stream-head->list (accelerated-sequence euler-transform ln2-stream) 10)