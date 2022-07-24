#lang racket/base
(define x 
  (list (list 1 2) (list 3 4)))

(define (fringe x)
  (if (not (pair? x))
      (list x)
      (append (fringe (car x))
              (fringe (car (cdr x))))))

(fringe x)

(define y (list x x))

(fringe y)

(define z (list y y))

(fringe z)

(fringe (list 1 (list 2 (list 3 4)) 5))

(define (enumerate-tree tree)
  (cond ((null? tree) null)
        ((not (pair? tree)) (list tree))
        (else (append 
               (enumerate-tree (car tree))
               (enumerate-tree (cdr tree))))))

(enumerate-tree (list 1 (list 2 (list 3 4)) 5))

(enumerate-tree z)