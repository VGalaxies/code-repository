#lang racket/base
(define (add-interval x y)
  (make-interval (+ (lower-bound x) 
                    (lower-bound y))
                 (+ (upper-bound x) 
                    (upper-bound y))))

(define (mul-interval x y)
  (let ((p1 (* (lower-bound x) 
               (lower-bound y)))
        (p2 (* (lower-bound x) 
               (upper-bound y)))
        (p3 (* (upper-bound x) 
               (lower-bound y)))
        (p4 (* (upper-bound x) 
               (upper-bound y))))
    (make-interval (min p1 p2 p3 p4)
                   (max p1 p2 p3 p4))))

(define (div-interval x y)
  (mul-interval x 
                (make-interval 
                 (/ 1.0 (upper-bound y)) 
                 (/ 1.0 (lower-bound y)))))

(define (make-interval a b) (cons a b))

(define (lower-bound x) (car x))

(define (upper-bound x) (cdr x))

(define (print-interval x)
  (display "[")
  (display (lower-bound x))
  (display ",")
  (display (upper-bound x))
  (display "]")
  (newline))

(print-interval (mul-interval (make-interval -1 2) (make-interval 3 4)))

(define (make-center-percent c p)
  (let ((w (* c p)))
    (make-interval (- c w) (+ c w))))

(define (center i)
  (/ (+ (lower-bound i) 
        (upper-bound i)) 
     2))

(define (percent i)
  (/ (- (upper-bound i) (center i))
     (center i)))

(percent (make-center-percent 3 0.5))

(define (par1 r1 r2)
  (div-interval 
   (mul-interval r1 r2)
   (add-interval r1 r2)))

(define (par2 r1 r2)
  (let ((one (make-interval 1 1)))
    (div-interval 
     one
     (add-interval 
      (div-interval one r1) 
      (div-interval one r2)))))

(define a (make-center-percent 3 0.1))

(define b (make-center-percent 3 0.0001))

(print-interval (div-interval a a))

(print-interval (div-interval a b))

(print-interval (par1 a a))

(print-interval (par2 a a))

(print-interval (par1 b b))

(print-interval (par2 b b))