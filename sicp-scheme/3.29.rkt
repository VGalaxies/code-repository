#lang racket/base

(require "./3.28.rkt")

(define (or-gate a1 a2 output)
  (let ((b (make-wire)) 
        (c (make-wire))
        (d (make-wire))
        )
    (inverter a1 b)
    (inverter a2 c)
    (and-gate b c d)
    (inverter d output)
    'ok))

;;;;;;;;;;;;;;;;;;;;;;;

(define a1 (make-wire))
(define a2 (make-wire))
(define output (make-wire))

(probe 'output output)
  
(or-gate a1 a2 output)

(set-signal! a1 1)
(set-signal! a2 1)
(propagate) ; output 7  New-value = 1
  
(set-signal! a1 0)
(set-signal! a2 0)
(propagate) ; output 14  New-value = 0
  
(set-signal! a1 1)
(set-signal! a2 0)
(propagate) ; output 21  New-value = 1