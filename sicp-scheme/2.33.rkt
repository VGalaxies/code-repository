#lang racket/base
(define (accumulate op initial sequence)
  (if (null? sequence)
      initial
      (op (car sequence)
          (accumulate op 
                      initial 
                      (cdr sequence)))))


(define (map p sequence)
  (accumulate (lambda (x y) (cons (p x) y))
              null sequence))

(define (square x) (* x x))

(map square (list 1 2 3))

(define (append seq1 seq2)
  (accumulate cons seq1 seq2))

(append (list 1 2 3) (list 1 2 3))

(define (length sequence)
  (accumulate (lambda (x y) (+ y 1)) 0 sequence))

(length (list 1 2 3))
