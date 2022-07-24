#lang racket/base
(define (cont-frac f g k)
  (define (aid f g st ed)
    (if (= st ed)
      (/ (f st) (g st))
      (/ (f st)
         (+ (g st) (aid f g (+ st 1) ed)))))
  (aid f g 1 k))

(define (tan-cf x k)
  (cont-frac 
   (lambda (i)
     (if (= i 1) 
	 x
	 (- (* x x))))
   (lambda (i)
     (- (* i 2.0) 1))
   k))

(tan-cf 1 100)