#lang racket/base
(define (make-account balance right-passwd)
  (define (withdraw amount)
    (if (>= balance amount)
        (begin (set! balance 
                     (- balance amount))
               balance)
        "Insufficient funds"))
  (define (deposit amount)
    (set! balance (+ balance amount))
    balance)

  (let ((try-passwd-count 0))
    ;; (call-the-cops)不加括号会有问题
    (define (call-the-cops)
      (displayln "call-the-cops"))
    (define (incorrect-password . args)
      (if (>= try-passwd-count 7)
          (call-the-cops)
          "Incorrect password"))
    (define (dispatch passwd m)
      (cond
        ((not (eq? passwd right-passwd))
         (begin (set! try-passwd-count (+ try-passwd-count 1))
                incorrect-password))
        (else
         (set! try-passwd-count 0)
         (cond ((eq? m 'withdraw) withdraw)
               ((eq? m 'deposit) deposit)
               (else (error "Unknown request: 
                 MAKE-ACCOUNT" m))))))
    dispatch))
  

(define acc (make-account 100 'secret-password))
((acc 'secret-password 'withdraw) 40)

((acc 'some-other-password 'deposit) 50)
((acc 'some-other-password 'deposit) 50)
((acc 'some-other-password 'deposit) 50)
((acc 'some-other-password 'deposit) 50)
((acc 'some-other-password 'deposit) 50)
((acc 'some-other-password 'deposit) 50)
((acc 'some-other-password 'deposit) 50)
((acc 'secret-password 'withdraw) 40)
((acc 'some-other-password 'deposit) 50)
