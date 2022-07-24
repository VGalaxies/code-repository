#lang racket/base
(define (random-in-range low high)
  (let ((range (- high low)))
    (+ low (* (random) range))))

(define (monte-carlo trials experiment)
  (define (iter trials-remaining trials-passed)
    (cond ((= trials-remaining 0)
           (/ trials-passed trials))
          ;; (experiment) 不加括号出大问题
          ((experiment)
           (iter (- trials-remaining 1) 
                 (+ trials-passed 1)))
          (else
           (iter (- trials-remaining 1) 
                 trials-passed))))
  (iter trials 0))


(define (estimate-integral predicate x1 x2 y1 y2 trials)
  (define (experiment)
    (predicate (random-in-range x1 x2)
               (random-in-range y1 y2)))
  (let ((square (* (abs (- x2 x1))
                   (abs (- y2 y1)))))
    (* square
       (monte-carlo trials experiment))))

(define (estimate-pi trials)
  (define (square x) (* x x))
  (define (inside-circle? x y)
    (< (+ (square x) (square y)) 1.0))
  (estimate-integral inside-circle? -1 1 -1 1 trials))

(estimate-pi 10000)
(exact->inexact (estimate-pi 10000))

