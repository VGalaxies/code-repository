#lang racket

(define (C n)
  (cond
    ((eq? n 1) 1)
    ((even? n) (C (/ n 2)))
    (else
     (C (add1 (* 3 n))))))

(C 12)

(C 1025)

(define (A n m)
  (cond
    ((zero? n) (add1 m))
    ((zero? m) (A (sub1 n) 1))
    (else
     (A (sub1 n)
        (A n (sub1 m))))))

(A 1 0)

(A 1 1)

(A 2 2)