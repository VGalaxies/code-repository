#lang racket/base

(require "3.50.rkt")
(require "3.53.rkt")
(provide zeros sub-streams mul-streams div-streams
         exp-series cosine-series sine-series)

(define (sub-streams s1 s2)
  (stream-map - s1 s2))
(define (mul-streams s1 s2)
  (stream-map * s1 s2))
(define (div-streams s1 s2)
  (stream-map / s1 s2))

(define zeros (cons-stream 0 zeros))
(define ones (cons-stream 1 ones))

(define series
  (div-streams ones integers))

(define (integrate-series stream)
  (mul-streams stream series))

(define exp-series
  (cons-stream 
   1 (integrate-series exp-series)))

(define cosine-series 
  (cons-stream 1 (sub-streams zeros (integrate-series sine-series))))

(define sine-series
  (cons-stream 0 (integrate-series cosine-series)))

(module* main #f
  (stream-head->list exp-series 10)
  (stream-head->list cosine-series 10)
  (stream-head->list sine-series 10)
)