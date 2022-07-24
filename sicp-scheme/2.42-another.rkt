#lang racket/base
(define (accumulate op initial sequence)
  (if (null? sequence)
      initial
      (op (car sequence)
          (accumulate op initial (cdr sequence)))))

(define (enumerate-interval low high)
  (if (> low high)
      null
      (cons low (enumerate-interval (+ low 1) high))))

(define (flatmap proc seq)
  (accumulate append null (map proc seq)))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(define empty-board null)

(define (safe? k positions)
  (define (same-row? v0 v1)
    (= (car v0) (car v1)))
  
  (define (same-diag? v0 v1)
    (= (abs (- (car v0) (car v1))) 
       (abs (- (cdr v0) (cdr v1)))))
  
  (let ((pair_list (map cons positions (enumerate-interval 1 k))))
    (let ((val (car pair_list))) 
      (= (length 
          (filter (lambda (x) 
                    (or (same-row? x val) (same-diag? x val)))
                  (cdr pair_list)))
         0))))

(define (adjoin-position new-row k rest-of-queens)
  (cons new-row rest-of-queens))
  
(define (queens board-size)
  (define (queen-cols k)
    (if (= k 0)
        (list empty-board)
        (filter 
          (lambda (positions) (safe? k positions))
          (flatmap
            (lambda (rest-of-queens)
              (map (lambda (new-row)
                     (adjoin-position new-row k rest-of-queens))
                   (enumerate-interval 1 board-size)))
            (queen-cols (- k 1))))))
  (queen-cols board-size))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(map cons '(3 1 4 2) (enumerate-interval 1 4))
(car (map cons '(3 1 4 2) (enumerate-interval 1 4)))
(caar (map cons '(3 1 4 2) (enumerate-interval 1 4)))
(cdar (map cons '(3 1 4 2) (enumerate-interval 1 4)))

(flatmap
 (lambda (rest-of-queens)
   (map (lambda (new-row)
          (adjoin-position new-row 5 rest-of-queens))
        (enumerate-interval 1 5)))
 (queens 4))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(queens 4)