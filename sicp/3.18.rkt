#lang sicp
(define (last-pair x)
  (if (null? (cdr x))
      x
      (last-pair (cdr x))))

(define (make-cycle x)
  (set-cdr! (last-pair x) x)
  x)

(define (element-of-set? x set)
  (cond ((null? set) false)
        ((eq? x (car set)) true)
        (else (element-of-set? x (cdr set)))))

(define (adjoin-set x set)
  (cons x set))

(define (check-cycle? x)
  (let ((visited '()))
    (define (check-cycle-set? x)
      (cond ((not (pair? x)) false)
            ((element-of-set? x visited) true)
            (else
              (set! visited (adjoin-set x visited))
              ;; 只可能是cdr部分指向一个序对或nil
              (check-cycle-set? (cdr x)))))
    (check-cycle-set? x)))


(define z1 (list 'a 'b 'c))
(check-cycle? z1)

(define x2 (cons 'a 'b))
(define z2 (cons 'c (cons x2 x2)))
(check-cycle? z2)

(define x3 (cons 'a 'b))
(define y3 (cons x3 x3))
(define z3 (cons y3 y3))
(check-cycle? z3)

(define z4 (list 'a 'b 'c))
(set-cdr! (cddr z4) z4)
(check-cycle? z4)