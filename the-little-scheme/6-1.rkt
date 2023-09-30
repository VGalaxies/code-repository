#lang racket

(define (atom? x)
  (and (not (pair? x)) (not (null? x))))

(define x '(1 + 2))

(define y '(1 + (2 * 3)))

(define (numbered? aexp)
  (cond
    ((atom? aexp)
     (number? aexp))
    (else
     (and (numbered? (car aexp))
          (numbered? (caddr aexp))))))


(define (value-infix nexp)
  (cond
    ((atom? nexp) nexp)
    ((eq? (cadr nexp)
          '+)
     (+ (value-infix (car nexp))
        (value-infix (caddr nexp))))
    ((eq? (cadr nexp)
          '*)
     (* (value-infix (car nexp))
        (value-infix (caddr nexp))))))

(value-infix x)

(value-infix y)


(define (value-prefix nexp)
  (cond
    ((atom? nexp) nexp)
    ((eq? (car nexp)
          '+)
     (+ (value-prefix (cadr nexp))
        (value-prefix (caddr nexp))))
    ((eq? (car nexp)
          '*)
     (* (value-prefix (cadr nexp))
        (value-prefix (caddr nexp))))))

(value-prefix '(+ 2 3))


(define (pre aexp)
  (car aexp))

(define (in aexp)
  (cadr aexp))

(define (post aexp)
  (caddr aexp))

(define (value-postfix nexp)
  (cond
    ((atom? nexp) nexp)
    ((eq? (post nexp)
          '+)
     (+ (value-postfix (pre nexp))
        (value-postfix (in nexp))))
    ((eq? (car nexp)
          '*)
     (* (value-postfix (pre nexp))
        (value-postfix (in nexp))))))

(value-postfix '(2 3 +))