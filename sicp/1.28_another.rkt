#lang racket/base
(define (square x) (* x x))

(define (nontrivial? a n)
  (and (not (= a 1))
       (not (= a (- n 1)))
       (= (remainder (square a) n) 1)))

(define (expmod base exp m)
  (cond ((= exp 0) 1)
        ((nontrivial? base m) 0)
        ((even? exp)
         (remainder (square (expmod base (/ exp 2) m))
                    m))
        (else
          (remainder (* base (expmod base (- exp 1) m))
                     m))))  

(define (fmiller-rabin-test n)
  (define (try-it a)
    (= (expmod a (- n 1) n) 1))
  (try-it (+ 1 (random (- n 1)))))

(define (fast-prime? n times)
  (cond ((= times 0) #t)
        ((fmiller-rabin-test n) (fast-prime? n (- times 1)))
        (else #f)))

(module* test #f
  (require rackunit)
  (for-each (lambda (num)
             (check-true (fast-prime? num 100)))
           '(2 3 5 7 11 13 17 19 23))
  (for-each (lambda (num)
             (check-false (fast-prime? num 100)))
           '(36 25 9 16 4 561 1105 1729 2465))
)