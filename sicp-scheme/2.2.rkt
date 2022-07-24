#lang racket/base
(define (print-point p)
  (newline)
  (display "(")
  (display (x-point p))
  (display ",")
  (display (y-point p))
  (display ")"))

(define (make-segment x y)
  (cons x y))

(define (start-segment x)
  (car x))

(define (end-segment x)
  (cdr x))

(define (make-point x y)
  (cons x y))

(define (x-point x)
  (car x))

(define (y-point x)
  (cdr x))

(define (average x y)
  (/ (+ x y) 2))

(define (midpoint-segment x)
  (let ((st (start-segment x))
        (ed (end-segment x)))
    (make-point (average (x-point st)
                         (x-point ed))
                (average (y-point st)
                         (y-point ed)))))

(define st (make-point 1 2))

(define ed (make-point 3 4))

(print-point (midpoint-segment (make-segment st ed)))
