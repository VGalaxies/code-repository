#lang racket

(define (multirember a lat)
  (cond
    ((null? lat) (quote()))
    ((eq? (car lat) a) (multirember a (cdr lat)))
    (else (cons (car lat)
                (multirember a (cdr lat))))))

(multirember 1 (list 2 1 3 1 4))


(define (multiinsertR new old lat)
  (cond
    ((null? lat) (quote()))
    ((eq? (car lat)
          old)
      (cons old (cons new (multiinsertR new old (cdr lat)))))
    (else
     (cons (car lat)
           (multiinsertR new old (cdr lat))))))

(multiinsertR 4 2 (list 1 2 5 2 6))

(define (multiinsertL new old lat)
  (cond
    ((null? lat) (quote()))
    ((eq? (car lat)
          old)
      (cons new (cons old (multiinsertL new old (cdr lat)))))
    (else
     (cons (car lat)
           (multiinsertL new old (cdr lat))))))

(multiinsertL 4 2 (list 1 2 5 2 6))


(define (multisubst new old lat)
  (cond
    ((null? lat) (quote()))
    ((eq? (car lat)
          old)
      (cons new (multisubst new old (cdr lat))))
    (else
     (cons (car lat)
           (multisubst new old (cdr lat))))))

(multisubst 4 2 (list 1 2 5 2 6))