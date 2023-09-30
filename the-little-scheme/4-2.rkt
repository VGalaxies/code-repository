#lang racket

(define (> n m)
  (cond
    ((zero? n) #f)
    ((zero? m) #t)
    (else (> (sub1 n) (sub1 m)))))

(> 3 2)

(> 3 3)

(> 3 4)

(define (< n m)
  (cond
    ((zero? m) #f)
    ((zero? n) #t)
    (else (< (sub1 n) (sub1 m)))))

(< 3 2)

(< 3 3)

(< 3 4)

(define (= n m)
  (cond
    ((or
      (< n m)
      (> n m))
     #f)
    (else #t)))

(= 3 2)