#lang racket

(define (multirember-co)
  (lambda (a lat col)
    (cond
      ((null? lat)
       (col (quote()) (quote())))
      ((eq? (car lat) a)
       ((multirember-co)
        a
        (cdr lat)
        (lambda (newlat seen)
          (col newlat
               (cons (car lat) seen)))))
      (else
       ((multirember-co)
        a
        (cdr lat)
        (lambda (newlat seen)
          (col (cons (car lat) newlat)
               seen)))))))


((multirember-co) 1 '(2) (lambda (x y) (null? y)))

((multirember-co) 1 '(1) (lambda (x y) (null? y)))

((multirember-co) 1 '(1 2 3) (lambda (x y) (list x y)))

((multirember-co) 1 '(1 2 3) (lambda (x y) (length x)))

((multirember-co) 1 '(1 2 3) (lambda (x y) (length y)))

(define (multiinsertLR)
  (lambda (new oldL oldR lat)
    (cond
      ((null? lat) (quote()))
      ((eq? (car lat)
            oldL)
       (cons new
             (cons oldL
                   ((multiinsertLR) new oldL oldR (cdr lat)))))
      ((eq? (car lat)
            oldR)
       (cons oldR
             (cons new
                   ((multiinsertLR) new oldL oldR (cdr lat)))))
      (else
       (cons (car lat)
             ((multiinsertLR) new oldL oldR (cdr lat)))))))

((multiinsertLR) '★ 1 2 '(1 2 3 2))

(define (multiinsertLR-co)
  (lambda (new oldL oldR lat col)
    (cond
      ((null? lat)
       (col (quote()) 0 0))
      ((eq? (car lat)
            oldL)
       ((multiinsertLR-co) new oldL oldR
                           (cdr lat)
                           (lambda (newlat L R)
                             (col (cons new (cons oldL newlat))
                                  (add1 L)
                                  R))))
      ((eq? (car lat)
            oldR)
       ((multiinsertLR-co) new oldL oldR
                           (cdr lat)
                           (lambda (newlat L R)
                             (col (cons oldR (cons new newlat))
                                  L
                                  (add1 R)))))
      (else
       ((multiinsertLR-co) new oldL oldR
                           (cdr lat)
                           (lambda (newlat L R)
                             (col (cons (car lat) newlat)
                                  L
                                  R)))))))

((multiinsertLR-co) '★ 1 2 '(1 2 3 2) (lambda (x y z) (list x y z)))