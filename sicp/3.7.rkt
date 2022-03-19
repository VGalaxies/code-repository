#lang racket/base
;; 定义函数处理剩余参数
(define (incorrect-password . args)
  "Incorrect password")

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
  (define (dispatch passwd m)
    (cond
      ((not (eq? passwd right-passwd)) incorrect-password)
      ((eq? m 'withdraw) withdraw)
      ((eq? m 'deposit) deposit)
      (else (error "Unknown request: 
                 MAKE-ACCOUNT" m))))
  dispatch)

(define (make-joint account old-passwd new-passwd)
  (define (check-password? account password)
    (number? ((account password 'withdraw) 0)))
  
  (if (check-password? account old-passwd)
      (lambda (try-password m)
        (if (eq? try-password new-passwd)
            ;; 使用原密码操作
            (account old-passwd m)
            incorrect-password))
      (incorrect-password)))

(define peter-acc (make-account 100 'open-sesame))
(define paul-acc (make-joint peter-acc 'open-sesame 'rosebud))

((peter-acc 'open-sesame 'withdraw) 40)
((paul-acc 'rosebud 'deposit) 50)
((peter-acc 'open-sesame 'withdraw) 70)
((paul-acc 'open-sesame 'deposit) 50)