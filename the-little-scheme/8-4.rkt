#lang racket

(define (atom? x)
  (and (not (pair? x)) (not (null? x))))

(define (even-only*)
  (lambda (l)
    (cond
      ((null? l) '())
      ((atom? (car l))
       (cond
         ((even? (car l))
          (cons (car l) ((even-only*) (cdr l))))
         (else
          ((even-only*) (cdr l)))))
      (else
       (cons ((even-only*) (car l))
             ((even-only*) (cdr l)))))))

((even-only*) (list 2 (list 1 3 2 (list 1)) 1 4))

(define (even-only*-co)
  (lambda (l col)
    (cond
      ((null? l)
       (col '() 1 0))
      ((atom? (car l))
       (cond
         ((even? (car l))
          ((even-only*-co) (cdr l)
                           (lambda (newl p s)
                             (col (cons (car l) newl)
                                  (* (car l) p)
                                  s))))
         (else
          ((even-only*-co) (cdr l)
                           (lambda (newl p s)
                             (col newl
                                  p
                                  (+ (car l) s)))))))
      (else
       ((even-only*-co) (car l)
                        (lambda (al ap as)
                          ((even-only*-co) (cdr l)
                                           (lambda (dl dp ds)
                                             (col (cons al dl)
                                                  (* ap dp)
                                                  (+ as ds))))))))))
(list 2 (list 1 3 2 (list 1)) 1 4)

((even-only*-co) (list 2 (list 1 3 2 (list 1)) 1 4)
              (lambda (x y z) (list x y z)))