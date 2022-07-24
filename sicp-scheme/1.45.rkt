#lang racket/base
(define (compose f g)
  (lambda (x) (f (g x))))

(define (repeated f n)
  (if (= n 0)
      (lambda (x) x)
      (lambda (x) ((compose f (repeated f (- n 1))) x))))

(define tolerance 0.00001)

(define (fixed-point f first-guess)
  (define (close-enough? v1 v2)
    (< (abs (- v1 v2)) 
       tolerance))
  (define (try guess)
    (let ((next (f guess)))
      (if (close-enough? guess next)
          next
          (try next))))
  (try first-guess))

(define (average x y) (/ (+ x y) 2))

(define (average-damp f)
  (lambda (x) 
    (average x (f x))))

(define (fixed-point-of-transform g transform guess)
  (fixed-point (transform g) guess))

(define (expt base n)
  (if (= n 0)
      1
      (* base (expt base (- n 1)))))

(define (expt-repeated base n)
    (if (= n 0)
        1
        ((repeated (lambda (x) (* base x)) n) 1)))

(define (extract-n-root x n)
  (fixed-point-of-transform (lambda (y) (/ x (expt y (- n 1))))
                            (repeated average-damp n)
                            1.0))

(extract-n-root 81 2)