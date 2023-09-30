#lang racket

(define (pick n lat)
  (cond
    ((zero? (sub1 n)) (car lat))
    (else
     (pick (sub1 n) (cdr lat)))))

(define (keep-looking a sorn lat)
  (cond
    ((number? sorn)
     (keep-looking a (pick sorn lat) lat))
    (else
     (eq? sorn a))))

(define (looking a lat)
  (keep-looking a (pick 1 lat) lat))

(looking 'a (list 6 2 'a 'b 5 7 3))

(looking 'a (list 6 2 'b 'a 5 7 3))