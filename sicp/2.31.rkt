#lang racket/base
(define (square x) (* x x))

(define (proc-tree proc tr)
  (cond ((null? tr) null)
        ((not (pair? tr)) (proc tr))
        (else (cons (proc-tree proc (car tr))
                    (proc-tree proc (cdr tr))))))

(define (proc-tree-map proc tr)
  (map (lambda (sub-tr)
         (if (pair? sub-tr)
             (proc-tree-map proc sub-tr)
             (proc sub-tr)))
       tr))

(define (square-tree tr) (proc-tree square tr))

(define (square-tree-map tr) (proc-tree-map square tr))

(square-tree
 (list 1
       (list 2 (list 3 4) 5)
       (list 6 7)))

(square-tree-map
 (list 1
       (list 2 (list 3 4) 5)
       (list 6 7)))