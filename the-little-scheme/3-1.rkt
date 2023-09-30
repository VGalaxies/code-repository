#lang racket

(define (rember a lat)
  (cond
    ((null? lat) (quote()))
    ((eq? (car lat) a) (cdr lat))
    (else (cons (car lat)
                (rember a (cdr lat))))))

(rember 1 (list 2 1 3 4))

(define (firsts l)
  (cond
    ((null? l) (quote()))
    (else (cons (caar l)
                (firsts (cdr l))))))

(firsts (list (list '(1) 2)
              (list 3 4)))

(cons 1 '())