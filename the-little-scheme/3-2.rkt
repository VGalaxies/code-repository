#lang racket

(define (insertR new old lat)
  (cond
    ((null? lat) (quote()))
    ((eq? (car lat)
          old)
      (cons old (cons new (cdr lat))))
    (else
     (cons (car lat)
           (insertR new old (cdr lat))))))

(insertR 4 2 (list 1 2 5 6))


(define (insertL new old lat)
  (cond
    ((null? lat) (quote()))
    ((eq? (car lat)
          old)
     ;(cons new lat)
      (cons new (cons old (cdr lat))))
    (else
     (cons (car lat)
           (insertL new old (cdr lat))))))

(insertL 4 2 (list 1 2 5 6))


(define (subst new old lat)
  (cond
    ((null? lat) (quote()))
    ((eq? (car lat)
          old)
      (cons new (cdr lat)))
    (else
     (cons (car lat)
           (subst new old (cdr lat))))))

(subst 4 2 (list 1 2 5 6))