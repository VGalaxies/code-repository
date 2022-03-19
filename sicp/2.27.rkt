#lang racket/base
(define (reverse i)
  (if (null? (cdr i))
      (list (car i))
      (append (reverse (cdr i)) (list (car i)))))

(define x 
  (list (list 1 2) (list 3 4)))

(reverse x)

(define (deep-reverse x)
  (if (not (pair? x))
      x
      (append (list (reverse (car (cdr x))))
              (list (reverse (car x))))))

(deep-reverse x)

(list x x)

(deep-reverse (list x x))

(define (deep-reverse-1 items)
  (define (iter items result)
    (if (null? items)
        result
        (iter (cdr items) 
              (cons (deep-reverse-1 (car items)) result))))
  (if (pair? items)
      (iter items null)
      items))

(define (deep-reverse-2 items)
  (cond ((null? items) null)
        ((not (pair? items)) items)
        (else (append (deep-reverse-2 (cdr items)) 
                      (list (deep-reverse-2 (car items)))))))

(define (deep-reverse-3 items)
  (cond ((null? items) null)
        ((not (pair? items)) items)
        (else (reverse (map deep-reverse-3 items)))))

(deep-reverse-1 (list x x))
(deep-reverse-2 (list x x))
(deep-reverse-3 (list x x))