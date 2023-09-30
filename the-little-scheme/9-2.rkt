#lang racket

(define (first p) (car p))

(define (second p) (cadr p))

(define (shift pair)
  (list (first (first pair))
        (list (second (first pair))
              (second pair))))

(shift (list (list 1 2) 3))
(shift (list (list 1 2) (list 3 4)))
(shift (list (list 1 2 (list 5 6)) (list 3 4)))

(define (atom? x)
  (and (not (pair? x)) (not (null? x))))

(define (a-pair? x)
  (cond
    ((atom? x) #f)
    ((null? x) #f)
    ((null? (cdr x)) #f)
    ((null? (cdr (cdr x))) #t)
    (else #f)))

(define (align pora)
  (cond
    ((atom? pora) pora)
    ((a-pair? (first pora))
     (align (shift pora)))
    (else
     (list (first pora)
           (align (second pora))))))

(list (list 1 (list 2 (list 3 4))) (list 5 (list 6 7)))
(align (list (list 1 (list 2 (list 3 4))) (list 5 (list 6 7))))

(define (length* pora)
  (cond
    ((atom? pora) 1)
    (else
     (+ (length* (first pora))
        (length* (second pora))))))

(length* (list (list 1 (list 2 (list 3 4))) (list 5 (list 6 7))))

(define (weight* pora)
  (cond
    ((atom? pora) 1)
    (else
     (+ (* 2
           (weight* (first pora)))
        (weight* (second pora))))))

(weight* (list (list 1 2) 3))
(weight* (list 1 (list 2 3)))

(define (revpair pair)
  (list (second pair)
        (first pair)))

(define (shuffle pora)
  (cond
    ((atom? pora) pora)
    ((a-pair? (first pora))
     (shuffle (revpair pora)))
    (else
     (list (first pora)
           (shuffle (second pora))))))

(shuffle (list (list (list 0 1) 2) 3))
(shuffle (list (list 1 2) 3))
(shuffle (list 1 (list 2 3)))
(shuffle (list 1 (list 2 (list 3 4))))