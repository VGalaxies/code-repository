#lang racket/base

(require "3.50.rkt")
(require "3.53.rkt")
(require "3.70.rkt")

(define (cube x) (* x x x))

(define (cube-sum pair)
  (let ((i (car pair))
        (j (cadr pair)))
    (+ (cube i) (cube j))))

(define ori-stream (weighted-pairs integers integers cube-sum))

(define (neighbor-same-weight list res weight)
  (if (not (null? (cdr list)))
      (let ((target (car list))
            (neighbor (cadr list)))
        (if (= (weight target)
               (weight neighbor))
            (neighbor-same-weight (cddr list)
                                  (append res (cons (weight target) '())) weight)
            (neighbor-same-weight (cdr list) res weight)))
      res))

(neighbor-same-weight (stream-head->list ori-stream 1000) '() cube-sum)

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; 下为hjcapple的解法

(define (ramanujan-filter s)
  (let ((s0 (stream-car s))
        (s1 (stream-car (stream-cdr s))))
    (if (= (cube-sum s0) (cube-sum s1))
        (cons-stream 
          (list (cube-sum s0) s0 s1)
          (ramanujan-filter (stream-cdr (stream-cdr s))))
        (ramanujan-filter (stream-cdr s)))))

(define ramanujan-numbers
  (ramanujan-filter (weighted-pairs integers integers cube-sum)))

(stream-head->list ramanujan-numbers 10)
