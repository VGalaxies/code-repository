#lang racket

(define (eternity)
  (lambda (x)
    (eternity x)))

(define (will-stop?)
  (lambda (f)
    ('...)))

;Return #t or #f, depending on whether the argument stops when applied to '().

(define (last-try x)
  (lambda (x)
    (and (will-stop? last-try)
       (eternity x))))

;If we can define will-stop?, then (will-stop? last-try) must yield either #t or #f. But it cannot-due to the very definition of what will-stop? is supposed to do. This must mean that will-stop? cannot be defined.
;We just saw that (define ... ) doesn't work for will-stop.