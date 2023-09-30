#lang racket

(define (rember-f-1 test? a lat)
  (cond
    ((null? lat) (quote()))
    ((test? (car lat) a) (cdr lat))
    (else (cons (car lat)
                (rember-f-1 a (cdr lat))))))

(rember-f-1 eq? 1 '(1 2 3))

(define (rember-f-2)
  (lambda (test? a lat)
    (cond
      ((null? lat) (quote()))
      ((test? (car lat) a) (cdr lat))
      (else (cons (car lat)
                  (rember-f-2 a (cdr lat)))))))

((rember-f-2) eq? 1 '(1 2 3))

(define (rember-f-3)
  (lambda (test?)
    (lambda (a lat)
      (cond
        ((null? lat) (quote()))
        ((test? (car lat) a) (cdr lat))
        (else (cons (car lat)
                    (rember-f-3 a (cdr lat))))))))

(((rember-f-3) eq?) 1 '(1 2 3))

(define eq?-c
  (lambda (a)
    (lambda (x)
      (eq? x a))))

(define (rember-f-4)
  (lambda (test?)
    (lambda (lat)
      (cond
        ((null? lat) (quote()))
        ((test? (car lat)) (cdr lat))
        (else (cons (car lat)
                    (rember-f-4 (cdr lat))))))))

(((rember-f-4) (eq?-c 1)) '(1 2 3))

(define (insert-g)
  (lambda (seq)
    (lambda (new old lat)
      (cond
        ((null? lat) (quote()))
        ((eq? (car lat) old)
         ((seq) new old (cdr lat)))
        (else
         (cons (car lat)
               (((insert-g) seq) new old (cdr lat))))))))

(define (seqL)
  (lambda (new old lat)
    (cons new (cons old lat))))

(define (seqR)
  (lambda (new old lat)
    (cons old (cons new lat))))

(define (seqS)
  (lambda (new old lat)
    (cons new lat)))

(((insert-g) seqL) 4 2 '(1 2 5 6))

(((insert-g) seqR) 4 2 '(1 2 5 6))

(((insert-g) seqS) 4 2 '(1 2 5 6))

(define (seqrem)
  (lambda (new old lat)
    lat))

(define (rember-f-5)
  (lambda (test?)
     (lambda (a lat)
       (((insert-g) seqrem) #f a lat))))

(((rember-f-5) eq?) 1 '(1 2 3))