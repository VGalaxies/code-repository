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
  ;; 定义函数处理剩余参数
  (define (incorrect-password . args)
    "Incorrect password")
  (define (dispatch passwd m)
    (cond
      ((not (eq? passwd right-passwd)) incorrect-password)
      ((eq? m 'withdraw) withdraw)
      ((eq? m 'deposit) deposit)
      (else (error "Unknown request: 
                 MAKE-ACCOUNT" m))))
  dispatch)

(define acc 
  (make-account 100 'secret-password))

((acc 'secret-password 'withdraw) 40)

((acc 'some-other-password 'deposit) 50)