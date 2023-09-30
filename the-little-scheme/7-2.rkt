#lang racket

(define (atom? x)
  (and (not (pair? x)) (not (null? x))))

(define (a-pair? x)
  (cond
    ((atom? x) #f)
    ((null? x) #f)
    ((null? (cdr x)) #f)
    ((null? (cdr (cdr x))) #t)
    (else #f)))

(a-pair? '())

(a-pair? 1)

(a-pair? '(1))

(a-pair? '(1 2))

(a-pair? '(1 2 3))

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

(define (firsts l)
  (cond
    ((null? l) (quote()))
    (else (cons (caar l)
                (firsts (cdr l))))))

(define (seconds l)
  (cond
    ((null? l) (quote()))
    (else (cons (cadar l)
                (seconds (cdr l))))))

(firsts (list '(1 2) '(1 3) '(2 4)))

(seconds (list '(1 2) '(1 3) '(2 4)))

(define (fun? rel)
  (set? (firsts rel)))

(fun? (list '(1 2) '(1 3) '(2 4)))

(fun? (list '(1 2) '(3 3) '(2 3)))

(define (first p) (car p))

(define (second p) (cadr p))

(define (build s1 s2)
  (cons s1 (cons s2 '())))

(define (revpair pair)
  (build (second pair)
         (first pair)))

(define (revrel rel)
  (cond
    ((null? rel) '())
    (else
     (cons (revpair (car rel))
           (revrel (cdr rel))))))

(revrel (list '(1 2) '(3 3) '(2 4)))

(define (full-fun? rel)
  ;(set? (seconds rel))
  (fun? (revrel rel)))

(full-fun? (list '(1 2) '(1 3) '(2 4)))

(full-fun? (list '(1 2) '(3 3) '(2 3)))