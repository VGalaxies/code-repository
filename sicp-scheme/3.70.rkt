#lang racket/base

(require "3.50.rkt")
(require "3.53.rkt")
(provide weighted-pairs)

(define (merge-weighted s1 s2 weight)
  (cond ((stream-null? s1) s2)
        ((stream-null? s2) s1)
        (else 
          (let ((w1 (weight (stream-car s1)))
                (w2 (weight (stream-car s2))))
            (cond ((< w1 w2)
                   (cons-stream (stream-car s1) (merge-weighted (stream-cdr s1) s2 weight)))
                  ((> w1 w2)
                   (cons-stream (stream-car s2) (merge-weighted s1 (stream-cdr s2) weight)))
                  (else
                    ;; 需要同时包含 (stream-car s1) 和 (stream-car s2) 两项
                    (cons-stream (stream-car s1)
                                 (cons-stream (stream-car s2)
                                              (merge-weighted (stream-cdr s1)
                                                              (stream-cdr s2)
                                                              weight)))))))))

(define (weighted-pairs s t weight)
  (cons-stream
   (list (stream-car s) (stream-car t))
   (merge-weighted
    (stream-map (lambda (x) 
                  (list (stream-car s) x))
                (stream-cdr t))
    (weighted-pairs (stream-cdr s) (stream-cdr t) weight)
    weight)))

(define (weight-1 pair)
  (+ (car pair) (cadr pair)))

(define (weight-2 pair)
  (let ((i (car pair))
        (j (cadr pair)))
    (+ (* 2 i) (* 3 j) (* 5 i j))))

(define filter-integers
  (stream-filter (lambda (x)
                   (or (= (remainder x 2) 0)
                       (= (remainder x 3) 0)
                       (= (remainder x 5) 0)))
                 integers))


(module* main #f
  (stream-head->list (weighted-pairs integers integers weight-1) 10)
  (stream-head->list (weighted-pairs filter-integers filter-integers weight-2) 10)
)