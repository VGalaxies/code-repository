#lang racket/base
(define accumulator
  (let ((sum 0))
    (lambda (now)
      (begin (set! sum (+ sum now))
             sum))))

(define (make-monitored fun)
  (let ((calls 0))
    (lambda (args)
      (if (eq? args 'how-many-calls?)
          calls
          (begin (set! calls (+ calls 1))
                 (fun args))))))

(define s (make-monitored accumulator))

(s 100)

(s 'how-many-calls?)

(s 100)

(s 'how-many-calls?)