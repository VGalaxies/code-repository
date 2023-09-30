#lang racket

(define (eternity)
  (lambda (x)
    ((eternity) x)))

((lambda (l)
  (cond
    ((null? l) 0)
    (else
      (add1 ((eternity) (cdr l))))))
 '())

((lambda (l)
  (cond
    ((null? l) 0)
    (else
      (add1
        ((lambda(l)
           (cond
             ((null? l) 0)
             (else
               (add1 ((eternity) (cdr l))))))
         (cdr l))))))
 '(1))

(((lambda (length)
   (lambda (l)
     (cond
       ((null? l) 0)
       (else (add1 (length (cdr l)))))))
 (eternity))
 '())

(((lambda (f)
   (lambda (l)
     (cond
       ((null? l) 0)
       (else (add1 (f (cdr l)))))))
 ((lambda (g)
    (lambda (l)
      (cond
        ((null? l) 0)
        (else (add1 (g (cdr l)))))))
  (eternity)))
 '(1))

(((lambda (mk-length)
   (mk-length mk-length))
 (lambda (mk-length)
   (lambda (l)
     (cond
       ((null? l) 0)
       (else
         (add1
           ((mk-length (eternity)) (cdr l))))))))
 '(1))

(((lambda (mk-length)
   (mk-length mk-length))
 (lambda (mk-length)
   (lambda (l)
     (cond
       ((null? l) 0)
       (else
         (add1
           ((mk-length mk-length) (cdr l))))))))
 '(1 2 3 4 5))

(((lambda (mk-length)
   (mk-length mk-length))
 (lambda (mk-length)
   ((lambda (length)
      (lambda (l)
        (cond
          ((null? l) 0)
          (else
            (add1 (length (cdr l)))))))
    (lambda (x)
      ((mk-length mk-length) x)))))
 '(1 2 3 4 5))

(((lambda (le)
   ((lambda (mk-length)
      (mk-length mk-length))
    (lambda (mk-length)
      (le (lambda (x)
            ((mk-length mk-length) x))))))
 (lambda (length)
   (lambda (l)
     (cond
       ((null? l) 0)
       (else (add1 (length (cdr l))))))))
 '(1 2 3 4 5))

(define Y
  (lambda (le)
    ((lambda (f) (f f))
     (lambda (f)
       (le (lambda (x) ((f f) x)))))))

((Y
 (lambda (length)
   (lambda (l)
     (cond
       ((null? l) 0)
       (else (add1 (length (cdr l))))))))
 '(1 2 3 4 5))