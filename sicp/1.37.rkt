#lang racket/base
;from st to ed
(define (cont-frac f g k)
  (define (aid f g st ed)
    (if (= st ed)
      (/ (f st) (g st))
      (/ (f st)
         (+ (g st) (aid f g (+ st 1) ed)))))
  (aid f g 1 k))

(cont-frac (lambda (i) 1.0)
           (lambda (i) 1.0)
           100)

;from ed to st
(define (cont-frac-iter f g k)
  (define (aid f g st ed result)
    (if (= st ed)
        result
        (aid f g st (- ed 1) (/ (f (- ed 1)) (+ (g (- ed 1)) result)))))
  (aid f g 1 k (/ (f k) (g k))))

(cont-frac-iter (lambda (i) 1.0)
           (lambda (i) 1.0)
           100)
