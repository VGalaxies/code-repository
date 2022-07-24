#lang racket/base
(define f1
  (let ((store-value 0))
    (lambda (x)
      (let ((old store-value))
        (set! store-value x)
        old))))

(define a1 (f1 0))
(define b1 (f1 1))
(+ a1 b1)

(define f2
  (let ((store-value 0))
    (lambda (x)
      (let ((old store-value))
        (set! store-value x)
        old))))

(define a2 (f2 1))
(define b2 (f2 0))
(+ a2 b2)

;; 注：将参数延迟一次调用后累加，初值为0。构造不唯一。