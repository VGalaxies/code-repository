#lang racket/base
(require "3.50.rkt")
(require "3.53.rkt")

(define (interleave s1 s2)
  (if (stream-null? s1)
      s2
      (cons-stream (stream-car s1)
                   (interleave s2 (stream-cdr s1)))))

(define (pairs s t)
  (interleave
   (stream-map (lambda (x) (list (stream-car s) x)) t)
   (pairs (stream-cdr s)
          (stream-cdr t))))

(stream-head->list (pairs integers integers) 100)