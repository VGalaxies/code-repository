#lang racket/base
(require "./3.28.rkt")

(define input-1 (make-wire))
(define input-2 (make-wire))
(define sum (make-wire))
(define carry (make-wire))

(probe 'sum sum)
(probe 'carry carry)

(half-adder input-1 input-2 sum carry)

(set-signal! input-1 1)

(set-signal! input-2 1)

(propagate)

(get-agenda-current-time)

;; 注：
;; 1、含(proc)时，sum会被监测到两次，由于一旦set-signal!后
;; 信号就会自动向后传递，两次非同时设置，但时间段相同
;; 2、不含(proc)时，只能通过手动set-signal!让信号传递过一个基本功能块