#lang racket/base
(define (square x) (* x x))

(define (smallest-divisor n)
  (find-divisor n 2))

(define (find-divisor n test-divisor)
  (cond ((> (square test-divisor) n) n)
        ((divides? test-divisor n) test-divisor)
        (else (find-divisor n (+ test-divisor 1)))))

(define (divides? a b)
  (= (remainder b a) 0))

(define (prime? n)
  (= n (smallest-divisor n)))

(define (expmod base exp m)
  (cond ((= exp 0) 1)
        ((even? exp)
         (remainder (square (expmod base (/ exp 2) m))
                    m))
        (else
          (remainder (* base (expmod base (- exp 1) m))
                     m))))  

(define (carmichael-test n)
  (define (fermat-test n a)
    (= (expmod a n n) a))
  
  (define (iter-test n a)
    (cond ((= a 0) #t)
          ((fermat-test n a) (iter-test n (- a 1)))
          (else #f)))
  
  (iter-test n (- n 1)))

(define (search-for-carmichae n count)
  (cond ((not (= count 0))
         (cond ((and (not (prime? n)) (carmichael-test n))
                (displayln n)
                (search-for-carmichae (+ n 1) (- count 1)))
               (else (search-for-carmichae (+ n 1) count))))))

;;;;;;;;;;;;;;;;;
(search-for-carmichae 1 10)