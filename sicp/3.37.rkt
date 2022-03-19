#lang racket/base

(require "./3.33.rkt")

(define (celsius-fahrenheit-converter x)
  (c+ (c* (c/ (cv 9) (cv 5))
          x)
      (cv 32)))

(define (c+ x y)
  (let ((z (make-connector)))
    (adder x y z)
    z))

(define (c* x y)
  (let ((z (make-connector)))
    (multiplier x y z)
    z))

(define (c/ x y)
  (let ((z (make-connector)))
    (multiplier y z x)
    z))

(define (cv c)
  (let ((z (make-connector)))
    (constant c z)
    z))

;;;;;;;;;;;;;;;;;;

(define C (make-connector))
(define F (celsius-fahrenheit-converter C))
  
(probe "Celsius temp" C)
(probe "Fahrenheit temp" F)
(set-value! C 25 'user)
  
(forget-value! C 'user)
(set-value! F 212 'user)

