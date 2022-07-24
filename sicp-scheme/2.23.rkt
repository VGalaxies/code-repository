#lang racket/base
(define (for-each proc items)
  (proc (car items))
  (if (null? (cdr items))
      (newline)
      (for-each proc (cdr items))))

(for-each 
 (lambda (x) (newline) (display x))
 (list 57 321 88))

(define (for-each-another proc items)
    (cond ((not (null? items))
           (proc (car items))
           (for-each-another proc (cdr items)))))

(for-each-another 
 (lambda (x) (newline) (display x))
 (list 57 321 88))

