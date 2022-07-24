#lang racket/base

(provide cons-stream stream-car stream-cdr stream-null? the-empty-stream)
(provide stream-enumerate-interval stream-for-each display-stream display-line)
(provide stream-filter stream-map stream-ref)
(provide force delay)

;;;;;;;;;;;;;;;;;;;

(define the-empty-stream '())
(define stream-null? null?)

(define (stream-car stream) 
  (car stream))
(define (stream-cdr stream) 
  (force (cdr stream)))

(define-syntax cons-stream
  (syntax-rules ()
    ((_ A B) (cons A (delay B)))))

(define (memo-proc proc)
  (let ((already-run? #f)
        (result #f))
    (lambda ()
      (if (not already-run?)
          (begin
            (set! result (proc))
            (set! already-run? #t)
            result)
          result))))

(define (force delayed-object)
  (delayed-object))

(define-syntax delay
  (syntax-rules ()
    ((_ exp) (memo-proc (lambda () exp)))))

;(define-syntax delay
;  (syntax-rules ()
;    ((_ exp) (lambda () exp))))

;(define (cons-stream a b)
;  (cons a (delay b)))
;(define (delay exp)
;  (lambda () exp))
;(define (force delayed-object)
;  (delayed-object))

;;;;;;;;;;;;;;;;;;;

(define (stream-ref s n)
  (if (= n 0)
      (stream-car s)
      (stream-ref (stream-cdr s) (- n 1))))

(define (stream-for-each proc s)
  (cond ((not (stream-null? s))
         (proc (stream-car s))
         (stream-for-each proc (stream-cdr s)))))

(define (stream-filter pred stream)
  (cond ((stream-null? stream) the-empty-stream)
        ((pred (stream-car stream))
         (cons-stream (stream-car stream)
                      (stream-filter pred
                                     (stream-cdr stream))))
        (else (stream-filter pred (stream-cdr stream)))))

(define (display-stream s)
  (stream-for-each display-line s))

(define (display-line x)
  (display x)
  (newline))

(define (stream-enumerate-interval low high)
  (if (> low high)
      the-empty-stream
      (cons-stream low
                   (stream-enumerate-interval (+ low 1) high))))

;;;;;;;;;;;;;;;;;;;

(define (stream-map proc . argstreams)
  (if (stream-null? (car argstreams))
      the-empty-stream
      (cons-stream
       (apply proc (map stream-car argstreams))
       (apply stream-map
              (cons proc 
                    (map stream-cdr 
                         argstreams))))))

;;;;;;;;;;;;;;;;;;;

(module* main #f
  (define a (stream-map +  
                        (stream-enumerate-interval 10 20)
                        (stream-enumerate-interval 20 30)
                        (stream-enumerate-interval 30 40)))
  (display-stream a)

  (define b (stream-map *
                        (stream-enumerate-interval 10 20)
                        (stream-enumerate-interval 20 30)
                        (stream-enumerate-interval 30 40)))
  (display-stream b)
)