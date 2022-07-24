#lang sicp

(define (last-pair x)
  (if (null? (cdr x))
      x 
      (last-pair (cdr x))))

(define (make-cycle x)
  (set-cdr! (last-pair x) x)
  x)


(define z (make-cycle (list 'a 'b 'c)))
;; DrRacket 可以检测到列表循环
z