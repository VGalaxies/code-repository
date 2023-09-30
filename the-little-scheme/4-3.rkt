#lang racket

(define (addtup tup)
  (cond
    ((null? tup) 0)
    (else
     (+ (car tup)
          (addtup (cdr tup))))))

(define (tup+ tup1 tup2)
  (cond
    ((null? tup1) tup2)
    ((null? tup2) tup1)
    (else
     (cons (+ (car tup1)
                (car tup2))
           (tup+ (cdr tup1)
                 (cdr tup2))))))
                 
(addtup (list 1 2 3))
(tup+ (list 1 2) (list 3 4 5))

(define (occur a lat)
  (cond
    ((null? lat) 0)
    ((eq? (car lat) a)
     (add1 (occur a (cdr lat))))
    (else (occur a (cdr lat)))))

(occur 1 (list 1 2 3 1))