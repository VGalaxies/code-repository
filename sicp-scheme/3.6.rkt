#lang racket/base
(define (rand-update x)
  (let ((a 48271) (b 19851020) (m 2147483647))
    (modulo (+ (* a x) b) m)))

(define random-init 7)

(define rand
  (let ((x random-init))
    (lambda (op)
       (cond ((eq? op 'generate)
              (lambda () (set! x (rand-update x))
                x))
             ((eq? op 'reset)
              (lambda (new-value) (set! x new-value)))
             (else
              (error "Unknown request -- RAND" op))))))

((rand 'generate))

((rand 'reset) 7)
(rand 'generate)
;; 注意括号问题