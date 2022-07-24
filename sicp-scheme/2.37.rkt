#lang racket/base
(map + (list 1 2 3) (list 40 50 60) (list 700 800 900))

(define (accumulate op initial sequence)
  (if (null? sequence)
      initial
      (op (car sequence)
          (accumulate op 
                      initial 
                      (cdr sequence)))))

(define (accumulate-n op init seqs)
  (if (null? (car seqs))
      null
      (cons (accumulate op init (map car seqs))
            (accumulate-n op init (map cdr seqs)))))

(define (dot-product v w)
  (accumulate + 0 (map * v w)))

(dot-product '(1 2 3) '(1 2 3))

(define (matrix-*-vector m v)
  (map (lambda (row) (dot-product v row)) m))

(matrix-*-vector '((1 2 3) (1 2 3)) '(1 2 3))

(define (transpose mat)
  (accumulate-n cons null mat))

(define (transpose-another mat)
  (apply map list (identity-n mat)))

(define (identity-n . x) (car x))

(transpose '((1 2 3) (1 2 3)))
(transpose-another '((1 2 3) (1 2 3)))

(define (matrix-*-matrix m n)
  (let ((cols (transpose n)))
    (map (lambda (row) (matrix-*-vector cols row)) m)))

(matrix-*-matrix '((1 1) (2 2) (3 3)) '((1 2 3) (1 2 3)))

(matrix-*-matrix '((1 2 3) (1 2 3)) '((1 1) (2 2) (3 3)))

