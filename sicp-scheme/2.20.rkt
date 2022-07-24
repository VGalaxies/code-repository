#lang racket/base
(define (select f x)
  (cond ((null? x) null)
        ((f (car x)) (append (list (car x)) (select f (cdr x))))
        (else (select f (cdr x)))))

(define (same-parity first . rest)
  (if (even? first)
      (append (list first) (select even? rest))
      (append (list first) (select odd? rest))))

(same-parity 1 2 3 4 5 6 7)

(same-parity 2 3 4 5 6 7)
