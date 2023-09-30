#lang racket

(define (atom? x)
  (and (not (pair? x)) (not (null? x))))

(define (pre aexp)
  (car aexp))

(define (in aexp)
  (cadr aexp))

(define (post aexp)
  (caddr aexp))

(define (atom-to-function)
  (lambda (x)
    (cond
      ((eq? x '+) +)
      ((eq? x 'x) x))))

(define (value-infix nexp)
  (cond
    ((atom? nexp) nexp)
    (else
     (((atom-to-function) (in nexp))
      (value-infix (pre nexp))
      (value-infix (post nexp))))))

(value-infix '(1 + 2))