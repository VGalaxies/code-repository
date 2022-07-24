#lang racket/base
(define (cont-frac f g k)
  (define (aid f g st ed)
    (if (= st ed)
      (/ (f st) (g st))
      (/ (f st)
         (+ (g st) (aid f g (+ st 1) ed)))))
  (aid f g 1 k))

(define (g n)
  (if (= (remainder (+ n 1) 3)
         0)
      (+ 1
         (/ (+ n 1) 3))
      1))

(+ 2 (cont-frac (lambda (x) 1.0) g 100000))