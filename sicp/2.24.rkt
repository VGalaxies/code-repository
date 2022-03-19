#lang racket/base
(list 1 2)

(cons 1 2)

(cons (list 1 2) (list 1 2))

(cons (list 1 2) (cons 1 (cons 2 null)))

(list (list 1 2) (list 1 2))

(list 1 (list 2 (list 3 4)))

(cons 1 (cons (cons 2 (cons (cons 3 (cons 4 null)) null)) null))