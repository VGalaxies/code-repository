#lang racket

(define (add n m)
  (cond
    ((zero? m) n)
    (else (add1
           (add n
                (sub1 m))))))


(define (sub n m)
  (cond
    ((zero? m) n)
    (else (sub1
           (sub n
                (sub1 m))))))


(define (mul n m)
  (cond
    ((zero? m) 0)
    (else
     (add n
          (mul n
               (sub1 m))))))

(define (div n m)
  (cond
    ((< n m) 0)
    (else
     (add1 (div (sub n m)
                m)))))


(define (expt n m)
  (cond
    ((zero? m) 1)
    (else (mul n
               (expt n (sub1 m))))))

(add 3 4)
(sub 3 4)
(mul 3 4)
(div 13 4)
(expt 2 3)