#lang racket/base
(define (make-mobile left right)
  (list left right))

(define (make-branch length structure)
  (list length structure))

(define (left-branch x)
  (car x))

(define (right-branch x)
  (car (cdr x)))

(define (branch-length x)
  (car x))

(define (branch-structure x)
  (car (cdr x)))

;(define (make-mobile left right)
;  (cons left right))

;(define (make-branch length structure)
;  (cons length structure))

;(define (left-branch mobile)
;  (car mobile))

;(define (right-branch mobile)
;  (cdr mobile))

;(define (branch-length branch)
;  (car branch))

;(define (branch-structure branch)
;  (cdr branch))


(define (total-weight-mobile x)
  (+ (total-weight-branch (left-branch x))
     (total-weight-branch (right-branch x))))

(define (total-weight-branch x)
  (if (pair? (branch-structure x))
      (total-weight-mobile (branch-structure x))
      (branch-structure x)))

(define x (make-branch 1 2))

(define y (make-mobile x (make-branch 1 (make-mobile x x))))

(total-weight-mobile y)

(define (balance-mobile x)
  (and (balance-branch (left-branch x))
       (balance-branch (right-branch x))
       (= (* (branch-length (left-branch x))
        (total-weight-branch (left-branch x)))
          (* (branch-length (right-branch x))
        (total-weight-branch (right-branch x))))))

(define (balance-branch x)
  (if (not (pair? (branch-structure x)))
      (* (branch-structure x)
         (branch-length x))
      (balance-mobile (branch-structure x))))

(balance-mobile y)

(define a (make-branch 1 2))

(define b (make-branch 1 3))

(define c (make-mobile a b))

(define d (make-mobile b a))

(define e (make-mobile
           (make-branch 1 c)
           (make-branch 1 d)))

(total-weight-mobile e)

(balance-mobile e)
