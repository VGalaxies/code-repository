#lang sicp

(#%require "serializer.rkt")

;; 注释的地方不太懂

(define (make-semaphore n)
  (let ((lock (make-mutex)))
    (define (the-semaphore m)
      (cond ((eq? m 'acquire)
             (lock 'acquire)
             (if (> n 0)
                 (begin
                   (set! n (- n 1))
                   (lock 'release)) ;;
                 (begin
                   (lock 'release) ;;
                   (the-semaphore 'acquire))))
            ((eq? m 'release)
             (lock 'acquire) ;;
             (set! n (+ n 1))
             (lock 'release))))
    the-semaphore))