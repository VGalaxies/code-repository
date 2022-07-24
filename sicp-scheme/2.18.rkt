#lang racket/base
(define (last-pair i)
  (if (null? (cdr i))
      (car i)
      (last-pair (cdr i))))

(define (reverse i)
  (if (null? (cdr i))
      (list (car i))
      (append (reverse (cdr i)) (list (car i)))))

(reverse (list 1 4 9 16 25))

(define (reverse-iter i)
  (define (aid i result)
    (if (null? i)
        result
        (aid (cdr i) (append (list (car i)) result))))
  (aid i '()))

(reverse-iter (list 1 4 9 16 25))
