#lang racket/base
(define (square x) (* x x))

(define (square-tree tr)
  (cond ((null? tr) null)
        ((not (pair? tr)) (square tr))
        (else (cons (square-tree (car tr))
                    (square-tree (cdr tr))))))

(square-tree
 (list 1
       (list 2 (list 3 4) 5)
       (list 6 7)))

(define (square-tree-map tr)
  (map (lambda (sub-tr)
         (if (pair? sub-tr)
             (square-tree-map sub-tr)
             (square sub-tr)))
       tr))

(square-tree-map
 (list 1
       (list 2 (list 3 4) 5)
       (list 6 7)))

