#lang racket

(define (atom? x)
  (and (not (pair? x)) (not (null? x))))

(define (rember* a l)
  (cond
    ((null? l) (quote()))
    ((atom? (car l))
     (cond
      ((eq? (car l) a)
       (rember* a (cdr l)))
      (else
       (cons (car l)
             (rember* a (cdr l))))))
    (else
     (cons (rember* a (car l))
           (rember* a (cdr l))))))

(rember* 1 (list 2 (list 1 (list 1 2)) 1))

(define (insertR* new old l)
  (cond
    ((null? l) (quote()))
    ((atom? (car l))
     (cond
      ((eq? (car l) old)
       (cons old
             (cons new
                   (insertR* new old (cdr l)))))
      (else
       (cons (car l)
             (insertR* new old (cdr l))))))
    (else
     (cons (insertR* new old (car l))
           (insertR* new old (cdr l))))))

(insertR* 3 1 (list 2 (list 1 (list 1 2)) 1))

(define (insertL* new old l)
  (cond
    ((null? l) (quote()))
    ((atom? (car l))
     (cond
      ((eq? (car l) old)
       (cons new
             (cons old
                   (insertL* new old (cdr l)))))
      (else
       (cons (car l)
             (insertL* new old (cdr l))))))
    (else
     (cons (insertL* new old (car l))
           (insertL* new old (cdr l))))))

(insertL* 3 1 (list 2 (list 1 (list 1 2)) 1))

(define (subst? new old l)
  (cond
    ((null? l) (quote()))
    ((atom? (car l))
     (cond
      ((eq? (car l) old)
       (cons new
             (subst? new old (cdr l))))
      (else
       (cons (car l)
             (subst? new old (cdr l))))))
    (else
     (cons (subst? new old (car l))
           (subst? new old (cdr l))))))

(subst? 3 1 (list 2 (list 1 (list 1 2)) 1))

(define (occur* a l)
  (cond
    ((null? l) 0)
    ((atom? (car l))
     (cond
      ((eq? (car l) a)
       (add1 (occur* a (cdr l))))
      (else (occur* a (cdr l)))))
    (else
     (+ (occur* a (car l))
        (occur* a (cdr l))))))

(occur* 1 (list 2 (list 1 (list 1 2)) 1))

(define (member? a l)
  (cond
    ((null? l) #f)
    ((atom? (car l))
     (or (eq? (car l) a)
         (member? a (cdr l))))
    (else
     (or (member? a (cdr l))
         (member? a (cdr l))))))

(member? 1 (list 2 (list 1 (list 1 2)) 1))