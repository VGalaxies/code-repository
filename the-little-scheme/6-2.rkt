#lang racket

(define (sero? n)
  (null? n))

(define (edd1 n)
  (cons '() n))

(define (zub1 n)
  (cdr n))

(define (edd n m)
  (cond
    ((sero? m) n)
    (else
     (edd1 (edd n (zub1 m))))))

(define zero '())

(define one (edd1 zero))

(define (atom? x)
  (and (not (pair? x)) (not (null? x))))

(define (lat? l)
  (cond
    ((null? l) #t)
    ((atom? (car l)) (lat? (cdr l)))
    (else #f)))

(lat? '(1 2))

(lat? '(one (edd1 one)))

(lat? zero)

(atom? zero)