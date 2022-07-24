#lang racket/base
(define (entry tree)
  (car tree))

(define (left-branch tree)
  (cadr tree))

(define (right-branch tree)
  (caddr tree))

(define (make-tree entry left right)
  (list entry left right))

(define (tree->list-1 tree)
  (if (null? tree)
      null 
      (append (tree->list-1 (left-branch tree))
              (cons (entry tree)
                    (tree->list-1 (right-branch tree))))))

(define (tree->list-2 tree)
  (define (copy-to-list tree result-list)
    (if (null? tree)
        result-list
        (copy-to-list (left-branch tree)
                      (cons (entry tree)
                            (copy-to-list (right-branch tree) result-list)))))
  (copy-to-list tree null))


;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(define a (make-tree 7
                     (make-tree 3
                                (make-tree 1 null null)
                                (make-tree 5 null null))
                     (make-tree 9
                                null 
                                (make-tree 11 null null))))
(define b (make-tree 3
                     (make-tree 1 null null)
                     (make-tree 7
                                (make-tree 5 null null)
                                (make-tree 9
                                           null
                                           (make-tree 11 null null)))))

(define c (make-tree 5
                     (make-tree 3
                                (make-tree 1 null null)
                                null)
                     (make-tree 9
                                (make-tree 7  null null)
                                (make-tree 11 null null))))

(tree->list-1 a) ; '(1 3 5 7 9 11)
(tree->list-2 a) ; '(1 3 5 7 9 11)

(tree->list-1 b) ; '(1 3 5 7 9 11)
(tree->list-2 b) ; '(1 3 5 7 9 11)

(tree->list-1 c) ; '(1 3 5 7 9 11)
(tree->list-2 c) ; '(1 3 5 7 9 11)

(tree->list-1 '(5 (1 () (3 () ())) (9 (7 () ()) (11 () ()))))
(tree->list-2 '(5 (1 () (3 () ())) (9 (7 () ()) (11 () ()))))