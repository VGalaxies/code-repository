#lang racket

(define (atom? x)
  (and (not (pair? x)) (not (null? x))))

(define (eqlist? l1 l2)
  (cond
    ((and (null? l1)
          (null? l2))
     #t)
    ((or (null? l1)
         (null? l2))
     #f)
    (else
     (and (equal? (car l1)
                  (car l2))
          (eqlist? (cdr l1)
                   (cdr l2))))))

(define (equal? s1 s2)
  (cond
    ((and (atom? s1)
          (atom? s2))
     (eq? s1 s2))
    ((or (atom? s1)
         (atom? s2))
     #f)
    (else
     (eqlist? s1 s2))))

(define x (list 1 (list 2) 'hello))

(define y (list 1 (list 2) 'hello))

(eqlist? x y)

;(eqlist? 1 1)

(equal? x y)

(equal? 1 1)

(eq? x y)

(eq? 1 1)

(eq? 'hello 'hello)