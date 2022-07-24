#lang racket/base
(define (equal? a b)
  (cond
    ((and (not (pair? a)) (not (pair? b)))
     (eq? a b))
    ((or (not (pair? a)) (not (pair? b)))
     #f)
    (else
     (and (equal? (car a) (car b))
          (equal? (cdr a) (cdr b))))))

(equal? '(this is a list) 
        '(this is a list))

(equal? '(this is a list) 
        '(this (is a) list))

(equal? 1 2)

(equal? 1 1)

;;;;;;;;;;;;;;;;;;;;
(symbol? 'Apple)
(symbol? 1)
(symbol? '1)