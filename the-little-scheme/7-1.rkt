#lang racket

(define (member? a lat)
  (cond
    ((null? lat) #f)
    (else (or (eq? (car lat) a)
              (member? a (cdr lat))))))

(define (set? lat)
  (cond
    ((null? lat) #t)
    ((member? (car lat)
              (cdr lat))
     #f)
    (else
     (set? (cdr lat)))))

(set? '(1 2 3 1))

(define (makeset lat)
  (cond
    ((null? lat) '())
    ((member? (car lat) (cdr lat))
     (makeset (cdr lat)))
    (else
     (cons (car lat)
           (makeset (cdr lat))))))

(define (multirember a lat)
  (cond
    ((null? lat) (quote()))
    ((eq? (car lat) a) (multirember a (cdr lat)))
    (else (cons (car lat)
                (multirember a (cdr lat))))))

(define (makeset-another lat)
  (cond
    ((null? lat) '()) 
    (else
     (cons (car lat)
           (multirember (car lat)
                        (cdr lat))))))

(makeset '(1 2 3 1))
(makeset-another '(1 2 3 1))

(define (subset? set1 set2)
  (cond
    ((null? set1) #t)
    (else
     (and (member? (car set1) set2)
          (subset? (cdr set1) set2)))))

(subset? '(1) '(1 2 3))

(define (eqset? set1 set2)
  (and
   (subset? set1 set2)
   (subset? set2 set1)))

(eqset? '(3 2 1) '(1 2 3))

(define (intersect? set1 set2)
  (cond
    ((null? set1) #f)
    (else
     (or (member? (car set1) set2)
         (intersect? (cdr set1) set2)))))

(intersect? '(1 2) '(2 3))

(define (intersect set1 set2)
  (cond
    ((null? set1) '())
    ((member? (car set1) set2)
     (cons (car set1)
           (intersect (cdr set1) set2)))
    (else
     (intersect (cdr set1) set2))))

(intersect '(1 2) '(2 3))

(define (union set1 set2)
  (cond
    ((null? set1) set2)
    ((member? (car set1) set2)
     (union (cdr set1) set2))
    (else
     (cons (car set1)
           (union (cdr set1) set2)))))

(union '(1 2) '(2 3))

(define (intersectall l-set)
  (cond
    ((null? (cdr l-set)) (car l-set))
    (else
     (intersect (car l-set)
                (intersectall (cdr l-set))))))

(intersectall (list '(1 2) '(2 3) '(5 2)))

(intersectall '('(1 2) '(1 2) '(5 2)))