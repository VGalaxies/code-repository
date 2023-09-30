#lang racket

(define (atom? x)
  (and (not (pair? x)) (not (null? x))))

(define (lat? l)
  (cond
    ((null? l) #t)
    ((atom? (car l)) (lat? (cdr l)))
    (else #f)))

(lat? (list 1 (quote())))

(lat? (list 1 2))

(define (member? a lat)
  (cond
    ((null? lat) #f)
    (else (or (eq? (car lat) a)
              (member? a (cdr lat))))))

(member? 1 (list 1 2))

(member? 1 (list 1 3))