#lang racket/base
(define (square-list-1 items)
  (define (iter things answer)
    (if (null? things)
        answer
        (iter (cdr things)
              (cons ((lambda (x) (* x x)) (car things))
                    answer))))
  (iter items null))

(square-list-1 (list 1 2 3 4))

(define (square-list-2 items)
  (define (iter things answer)
    (if (null? things)
        answer
        (iter (cdr things)
              (cons answer
                    ((lambda (x) (* x x)) 
                     (car things))))))
  (iter items null))

(square-list-2 (list 1 2 3 4))