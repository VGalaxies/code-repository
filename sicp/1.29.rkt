#lang racket/base
(define (sum term a next b count)
  (cond ((> a b) 0)
        ((or (= count 0) (= a b))
         (+ (term a) (sum term (next a) next b (+ count 1))))
        ((odd? count)
         (+ (* 4 (term a)) (sum term (next a) next b (+ count 1))))
        (else
         (+ (* 2 (term a)) (sum term (next a) next b (+ count 1))))))

(define (integral f a b n)
  (let ((h (/ (- b a) n)))
    (define (next x) (+ x h))
    (* (/ h 3.0)
       (sum f a next b 0))))

(define (cube x) (* x x x))

(integral cube 0 1 100)