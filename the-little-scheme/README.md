# The Little Schemer

## Toys

### 定义的递归

**S-expression**

- all atoms are S-expressions.

- all lists are S-expressions.

- list are a collection of S-expressions enclosed by parentheses.

- null list contains zero S-expressions enclosed by parentheses.

### 字面量

`(quote ())` is a notation for the null list.

> quote 可以缩写为 `'`，作用是原样输出，如 `(quote ())` 等价于 `'()`

## Do It, Do It Again, and Again, and Again 

### 过程的递归

```scheme
(define (atom? x)
  (and (not (pair? x)) (not (null? x))))

(define (lat? l)
  (cond
    ((null? l) #t)
    ((atom? (car l)) (lat? (cdr l)))
    (else #f)))

(lat? (list 1 (quote())))

(lat? (list 1 2))

(define (member? a lat)
  (cond
    ((null? lat) #f)
    (else (or (eq? (car lat) a)
              (member? a (cdr lat))))))

(member? 1 (list 1 2))

(member? 1 (list 1 3))
```

## Cons the Magnificent

### cons

```scheme
(define (rember a lat)
  (cond
    ((null? lat) (quote()))
    ((eq? (car lat) a) (cdr lat))
    (else (cons (car lat)
                (rember a (cdr lat))))))

(rember 1 (list 2 1 3 4))

(define (firsts l)
  (cond
    ((null? l) (quote()))
    (else (cons (caar l)
                (firsts (cdr l))))))

(firsts (list (list '(1) 2)
              (list 3 4)))

(cons 1 '())
```

### 插入与替换

```scheme
(define (insertR new old lat)
  (cond
    ((null? lat) (quote()))
    ((eq? (car lat)
          old)
      (cons old (cons new (cdr lat))))
    (else
     (cons (car lat)
           (insertR new old (cdr lat))))))

(insertR 4 2 (list 1 2 5 6))


(define (insertL new old lat)
  (cond
    ((null? lat) (quote()))
    ((eq? (car lat)
          old)
     ;(cons new lat)
      (cons new (cons old (cdr lat))))
    (else
     (cons (car lat)
           (insertL new old (cdr lat))))))

(insertL 4 2 (list 1 2 5 6))


(define (subst new old lat)
  (cond
    ((null? lat) (quote()))
    ((eq? (car lat)
          old)
      (cons new (cdr lat)))
    (else
     (cons (car lat)
           (subst new old (cdr lat))))))

(subst 4 2 (list 1 2 5 6))
```

### 多重化

```scheme
(define (multirember a lat)
  (cond
    ((null? lat) (quote()))
    ((eq? (car lat) a) (multirember a (cdr lat)))
    (else (cons (car lat)
                (multirember a (cdr lat))))))

(multirember 1 (list 2 1 3 1 4))


(define (multiinsertR new old lat)
  (cond
    ((null? lat) (quote()))
    ((eq? (car lat)
          old)
      (cons old (cons new (multiinsertR new old (cdr lat)))))
    (else
     (cons (car lat)
           (multiinsertR new old (cdr lat))))))

(multiinsertR 4 2 (list 1 2 5 2 6))

(define (multiinsertL new old lat)
  (cond
    ((null? lat) (quote()))
    ((eq? (car lat)
          old)
      (cons new (cons old (multiinsertL new old (cdr lat)))))
    (else
     (cons (car lat)
           (multiinsertL new old (cdr lat))))))

(multiinsertL 4 2 (list 1 2 5 2 6))


(define (multisubst new old lat)
  (cond
    ((null? lat) (quote()))
    ((eq? (car lat)
          old)
      (cons new (multisubst new old (cdr lat))))
    (else
     (cons (car lat)
           (multisubst new old (cdr lat))))))

(multisubst 4 2 (list 1 2 5 2 6))
```

## Numbers Games

### 四则运算

```scheme
(define (add n m)
  (cond
    ((zero? m) n)
    (else (add1
           (add n
                (sub1 m))))))


(define (sub n m)
  (cond
    ((zero? m) n)
    (else (sub1
           (sub n
                (sub1 m))))))


(define (mul n m)
  (cond
    ((zero? m) 0)
    (else
     (add n
          (mul n
               (sub1 m))))))

(define (div n m)
  (cond
    ((< n m) 0)
    (else
     (add1 (div (sub n m)
                m)))))


(define (expt n m)
  (cond
    ((zero? m) 1)
    (else (mul n
               (expt n (sub1 m))))))

(add 3 4)
(sub 3 4)
(mul 3 4)
(div 13 4)
(expt 2 3)
```

### 大小比较

```scheme
(define (> n m)
  (cond
    ((zero? n) #f)
    ((zero? m) #t)
    (else (> (sub1 n) (sub1 m)))))

(> 3 2)

(> 3 3)

(> 3 4)

(define (< n m)
  (cond
    ((zero? m) #f)
    ((zero? n) #t)
    (else (< (sub1 n) (sub1 m)))))

(< 3 2)

(< 3 3)

(< 3 4)

(define (= n m)
  (cond
    ((or
      (< n m)
      (> n m))
     #f)
    (else #t)))

(= 3 2)
```

### 数字与列表的联姻

```scheme
(define (addtup tup)
  (cond
    ((null? tup) 0)
    (else
     (+ (car tup)
          (addtup (cdr tup))))))

(define (tup+ tup1 tup2)
  (cond
    ((null? tup1) tup2)
    ((null? tup2) tup1)
    (else
     (cons (+ (car tup1)
                (car tup2))
           (tup+ (cdr tup1)
                 (cdr tup2))))))
                 
(addtup (list 1 2 3))
(tup+ (list 1 2) (list 3 4 5))

(define (occur a lat)
  (cond
    ((null? lat) 0)
    ((eq? (car lat) a)
     (add1 (occur a (cdr lat))))
    (else (occur a (cdr lat)))))

(occur 1 (list 1 2 3 1))
```

## `*Oh My Gawd*` : It's Full of Stars

### 树形递归

```scheme
(define (atom? x)
  (and (not (pair? x)) (not (null? x))))

(define (rember* a l)
  (cond
    ((null? l) (quote()))
    ((atom? (car l))
     (cond
      ((eq? (car l) a)
       (rember* a (cdr l)))
      (else
       (cons (car l)
             (rember* a (cdr l))))))
    (else
     (cons (rember* a (car l))
           (rember* a (cdr l))))))

(rember* 1 (list 2 (list 1 (list 1 2)) 1))

(define (insertR* new old l)
  (cond
    ((null? l) (quote()))
    ((atom? (car l))
     (cond
      ((eq? (car l) old)
       (cons old
             (cons new
                   (insertR* new old (cdr l)))))
      (else
       (cons (car l)
             (insertR* new old (cdr l))))))
    (else
     (cons (insertR* new old (car l))
           (insertR* new old (cdr l))))))

(insertR* 3 1 (list 2 (list 1 (list 1 2)) 1))

(define (insertL* new old l)
  (cond
    ((null? l) (quote()))
    ((atom? (car l))
     (cond
      ((eq? (car l) old)
       (cons new
             (cons old
                   (insertL* new old (cdr l)))))
      (else
       (cons (car l)
             (insertL* new old (cdr l))))))
    (else
     (cons (insertL* new old (car l))
           (insertL* new old (cdr l))))))

(insertL* 3 1 (list 2 (list 1 (list 1 2)) 1))

(define (subst? new old l)
  (cond
    ((null? l) (quote()))
    ((atom? (car l))
     (cond
      ((eq? (car l) old)
       (cons new
             (subst? new old (cdr l))))
      (else
       (cons (car l)
             (subst? new old (cdr l))))))
    (else
     (cons (subst? new old (car l))
           (subst? new old (cdr l))))))

(subst? 3 1 (list 2 (list 1 (list 1 2)) 1))

(define (occur* a l)
  (cond
    ((null? l) 0)
    ((atom? (car l))
     (cond
      ((eq? (car l) a)
       (add1 (occur* a (cdr l))))
      (else (occur* a (cdr l)))))
    (else
     (+ (occur* a (car l))
        (occur* a (cdr l))))))

(occur* 1 (list 2 (list 1 (list 1 2)) 1))

(define (member? a l)
  (cond
    ((null? l) #f)
    ((atom? (car l))
     (or (eq? (car l) a)
         (member? a (cdr l))))
    (else
     (or (member? a (cdr l))
         (member? a (cdr l))))))

(member? 1 (list 2 (list 1 (list 1 2)) 1))
```

### 非树形递归

```scheme
(define (atom? x)
  (and (not (pair? x)) (not (null? x))))

(define (leftmost l)
  (cond
    ((atom? (car l))
     (car l))
    (else
     (leftmost (car l)))))

(leftmost '(((1)) 1 (1 2) 3))
```

### 简化的艺术

语言规范似乎不一致

```scheme
(define (atom? x)
  (and (not (pair? x)) (not (null? x))))

(define (eqlist? l1 l2)
  (cond
    ((and (null? l1)
          (null? l2))
     #t)
    ((or (null? l1)
         (null? l2))
     #f)
    (else
     (and (equal? (car l1)
                  (car l2))
          (eqlist? (cdr l1)
                   (cdr l2))))))

(define (equal? s1 s2)
  (cond
    ((and (atom? s1)
          (atom? s2))
     (eq? s1 s2))
    ((or (atom? s1)
         (atom? s2))
     #f)
    (else
     (eqlist? s1 s2))))

(define x (list 1 (list 2) 'hello))

(define y (list 1 (list 2) 'hello))

(eqlist? x y)

;(eqlist? 1 1)

(equal? x y)

(equal? 1 1)

(eq? x y)

(eq? 1 1)

(eq? 'hello 'hello)
```

## Shadows

### 算术表达式的判定与计算

算术表达式以列表形式呈现

```scheme
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
```

### 数字的另一种表示

```scheme
(define (sero? n)
  (null? n))

(define (edd1 n)
  (cons '() n))

(define (zub1 n)
  (cdr n))

(define (edd n m)
  (cond
    ((sero? m) n)
    (else
     (edd1 (edd n (zub1 m))))))

(define zero '())

(define one (edd1 zero))

(define (atom? x)
  (and (not (pair? x)) (not (null? x))))

(define (lat? l)
  (cond
    ((null? l) #t)
    ((atom? (car l)) (lat? (cdr l)))
    (else #f)))

(lat? '(1 2))

(lat? '(one (edd1 one)))

(lat? zero)

(atom? zero)
```

## Friends and Relations

### set

- 集合的判定与创建
- 子集判定
- 集合的交与并
- 集合的广义交

```scheme
(define (member? a lat)
  (cond
    ((null? lat) #f)
    (else (or (eq? (car lat) a)
              (member? a (cdr lat))))))

(define (set? lat)
  (cond
    ((null? lat) #t)
    ((member? (car lat)
              (cdr lat))
     #f)
    (else
     (set? (cdr lat)))))

(set? '(1 2 3 1))

(define (makeset lat)
  (cond
    ((null? lat) '())
    ((member? (car lat) (cdr lat))
     (makeset (cdr lat)))
    (else
     (cons (car lat)
           (makeset (cdr lat))))))

(define (multirember a lat)
  (cond
    ((null? lat) (quote()))
    ((eq? (car lat) a) (multirember a (cdr lat)))
    (else (cons (car lat)
                (multirember a (cdr lat))))))

(define (makeset-another lat)
  (cond
    ((null? lat) '()) 
    (else
     (cons (car lat)
           (multirember (car lat)
                        (cdr lat))))))

(makeset '(1 2 3 1))
(makeset-another '(1 2 3 1))

(define (subset? set1 set2)
  (cond
    ((null? set1) #t)
    (else
     (and (member? (car set1) set2)
          (subset? (cdr set1) set2)))))

(subset? '(1) '(1 2 3))

(define (eqset? set1 set2)
  (and
   (subset? set1 set2)
   (subset? set2 set1)))

(eqset? '(3 2 1) '(1 2 3))

(define (intersect? set1 set2)
  (cond
    ((null? set1) #f)
    (else
     (or (member? (car set1) set2)
         (intersect? (cdr set1) set2)))))

(intersect? '(1 2) '(2 3))

(define (intersect set1 set2)
  (cond
    ((null? set1) '())
    ((member? (car set1) set2)
     (cons (car set1)
           (intersect (cdr set1) set2)))
    (else
     (intersect (cdr set1) set2))))

(intersect '(1 2) '(2 3))

(define (union set1 set2)
  (cond
    ((null? set1) set2)
    ((member? (car set1) set2)
     (union (cdr set1) set2))
    (else
     (cons (car set1)
           (union (cdr set1) set2)))))

(union '(1 2) '(2 3))

(define (intersectall l-set)
  (cond
    ((null? (cdr l-set)) (car l-set))
    (else
     (intersect (car l-set)
                (intersectall (cdr l-set))))))

(intersectall (list '(1 2) '(2 3) '(5 2)))

(intersectall '('(1 2) '(1 2) '(5 2)))
```

### pair

用 pair 表示 fun

```scheme
(define (atom? x)
  (and (not (pair? x)) (not (null? x))))

(define (a-pair? x)
  (cond
    ((atom? x) #f)
    ((null? x) #f)
    ((null? (cdr x)) #f)
    ((null? (cdr (cdr x))) #t)
    (else #f)))

(a-pair? '())

(a-pair? 1)

(a-pair? '(1))

(a-pair? '(1 2))

(a-pair? '(1 2 3))

(define (member? a lat)
  (cond
    ((null? lat) #f)
    (else (or (eq? (car lat) a)
              (member? a (cdr lat))))))

(define (set? lat)
  (cond
    ((null? lat) #t)
    ((member? (car lat)
              (cdr lat))
     #f)
    (else
     (set? (cdr lat)))))

(define (firsts l)
  (cond
    ((null? l) (quote()))
    (else (cons (caar l)
                (firsts (cdr l))))))

(define (seconds l)
  (cond
    ((null? l) (quote()))
    (else (cons (cadar l)
                (seconds (cdr l))))))

(firsts (list '(1 2) '(1 3) '(2 4)))

(seconds (list '(1 2) '(1 3) '(2 4)))

(define (fun? rel)
  (set? (firsts rel)))

(fun? (list '(1 2) '(1 3) '(2 4)))

(fun? (list '(1 2) '(3 3) '(2 3)))

(define (first p) (car p))

(define (second p) (cadr p))

(define (build s1 s2)
  (cons s1 (cons s2 '())))

(define (revpair pair)
  (build (second pair)
         (first pair)))

(define (revrel rel)
  (cond
    ((null? rel) '())
    (else
     (cons (revpair (car rel))
           (revrel (cdr rel))))))

(revrel (list '(1 2) '(3 3) '(2 4)))

(define (full-fun? rel)
  ;(set? (seconds rel))
  (fun? (revrel rel)))

(full-fun? (list '(1 2) '(1 3) '(2 4)))

(full-fun? (list '(1 2) '(3 3) '(2 3)))
```

## Lambda the Ultimate

### the power of abstraction

rember 的多重影分身

统一插入与替换

**Currying**

```scheme
(define (rember-f-1 test? a lat)
  (cond
    ((null? lat) (quote()))
    ((test? (car lat) a) (cdr lat))
    (else (cons (car lat)
                (rember-f-1 a (cdr lat))))))

(rember-f-1 eq? 1 '(1 2 3))

(define (rember-f-2)
  (lambda (test? a lat)
    (cond
      ((null? lat) (quote()))
      ((test? (car lat) a) (cdr lat))
      (else (cons (car lat)
                  (rember-f-2 a (cdr lat)))))))

((rember-f-2) eq? 1 '(1 2 3))

(define (rember-f-3)
  (lambda (test?)
    (lambda (a lat)
      (cond
        ((null? lat) (quote()))
        ((test? (car lat) a) (cdr lat))
        (else (cons (car lat)
                    (rember-f-3 a (cdr lat))))))))

(((rember-f-3) eq?) 1 '(1 2 3))

(define eq?-c
  (lambda (a)
    (lambda (x)
      (eq? x a))))

(define (rember-f-4)
  (lambda (test?)
    (lambda (lat)
      (cond
        ((null? lat) (quote()))
        ((test? (car lat)) (cdr lat))
        (else (cons (car lat)
                    (rember-f-4 (cdr lat))))))))

(((rember-f-4) (eq?-c 1)) '(1 2 3))

(define (insert-g)
  (lambda (seq)
    (lambda (new old lat)
      (cond
        ((null? lat) (quote()))
        ((eq? (car lat) old)
         ((seq) new old (cdr lat)))
        (else
         (cons (car lat)
               (((insert-g) seq) new old (cdr lat))))))))

(define (seqL)
  (lambda (new old lat)
    (cons new (cons old lat))))

(define (seqR)
  (lambda (new old lat)
    (cons old (cons new lat))))

(define (seqS)
  (lambda (new old lat)
    (cons new lat)))

(((insert-g) seqL) 4 2 '(1 2 5 6))

(((insert-g) seqR) 4 2 '(1 2 5 6))

(((insert-g) seqS) 4 2 '(1 2 5 6))

(define (seqrem)
  (lambda (new old lat)
    lat))

(define (rember-f-5)
  (lambda (test?)
     (lambda (a lat)
       (((insert-g) seqrem) #f a lat))))

(((rember-f-5) eq?) 1 '(1 2 3))
```

简化算术表达式的计算

```scheme
(define (atom? x)
  (and (not (pair? x)) (not (null? x))))

(define (pre aexp)
  (car aexp))

(define (in aexp)
  (cadr aexp))

(define (post aexp)
  (caddr aexp))

(define (atom-to-function)
  (lambda (x)
    (cond
      ((eq? x '+) +)
      ((eq? x 'x) x))))

(define (value-infix nexp)
  (cond
    ((atom? nexp) nexp)
    (else
     (((atom-to-function) (in nexp))
      (value-infix (pre nexp))
      (value-infix (post nexp))))))

(value-infix '(1 + 2))
```

### collector

**Continuation-passing style**

[怎样理解 Continuation-passing style?](https://www.zhihu.com/question/20259086)

非树形递归

```scheme
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
```

树形递归

```scheme
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
```

## ... and Again, and Again, and Again, 

### partial function

```scheme
(define (pick n lat)
  (cond
    ((zero? (sub1 n)) (car lat))
    (else
     (pick (sub1 n) (cdr lat)))))

(define (keep-looking a sorn lat)
  (cond
    ((number? sorn)
     (keep-looking a (pick sorn lat) lat))
    (else
     (eq? sorn a))))

(define (looking a lat)
  (keep-looking a (pick 1 lat) lat))

(looking 'a (list 6 2 'a 'b 5 7 3))

(looking 'a (list 6 2 'b 'a 5 7 3))
```

另一个例子

```scheme
(define (first p) (car p))

(define (second p) (cadr p))

(define (shift pair)
  (list (first (first pair))
        (list (second (first pair))
              (second pair))))

(shift (list (list 1 2) 3))
(shift (list (list 1 2) (list 3 4)))
(shift (list (list 1 2 (list 5 6)) (list 3 4)))

(define (atom? x)
  (and (not (pair? x)) (not (null? x))))

(define (a-pair? x)
  (cond
    ((atom? x) #f)
    ((null? x) #f)
    ((null? (cdr x)) #f)
    ((null? (cdr (cdr x))) #t)
    (else #f)))

(define (align pora)
  (cond
    ((atom? pora) pora)
    ((a-pair? (first pora))
     (align (shift pora)))
    (else
     (list (first pora)
           (align (second pora))))))

(list (list 1 (list 2 (list 3 4))) (list 5 (list 6 7)))
(align (list (list 1 (list 2 (list 3 4))) (list 5 (list 6 7))))

(define (length* pora)
  (cond
    ((atom? pora) 1)
    (else
     (+ (length* (first pora))
        (length* (second pora))))))

(length* (list (list 1 (list 2 (list 3 4))) (list 5 (list 6 7))))

(define (weight* pora)
  (cond
    ((atom? pora) 1)
    (else
     (+ (* 2
           (weight* (first pora)))
        (weight* (second pora))))))

(weight* (list (list 1 2) 3))
(weight* (list 1 (list 2 3)))

(define (revpair pair)
  (list (second pair)
        (first pair)))

(define (shuffle pora)
  (cond
    ((atom? pora) pora)
    ((a-pair? (first pora))
     (shuffle (revpair pora)))
    (else
     (list (first pora)
           (shuffle (second pora))))))

(shuffle (list (list (list 0 1) 2) 3))
(shuffle (list (list 1 2) 3))
(shuffle (list 1 (list 2 3)))
(shuffle (list 1 (list 2 (list 3 4))))
```

### 递归函数的可计算性

```scheme
(define (C n)
  (cond
    ((eq? n 1) 1)
    ((even? n) (C (/ n 2)))
    (else
     (C (add1 (* 3 n))))))

(C 12)

(C 1025)

(define (A n m)
  (cond
    ((zero? n) (add1 m))
    ((zero? m) (A (sub1 n) 1))
    (else
     (A (sub1 n)
        (A n (sub1 m))))))

(A 1 0)

(A 1 1)

(A 2 2)
```

### 停机问题

```scheme
(define (eternity)
  (lambda (x)
    (eternity x)))

(define (will-stop?)
  (lambda (f)
    ('...)))

;Return #t or #f, depending on whether the argument stops when applied to '().

(define (last-try x)
  (lambda (x)
    (and (will-stop? last-try)
       (eternity x))))

;If we can define will-stop?, then (will-stop? last-try) must yield either #t or #f. But it cannot-due to the very definition of what will-stop? is supposed to do. This must mean that will-stop? cannot be defined.
;We just saw that (define ... ) doesn't work for will-stop.
```

### Applicative-order Y Combinator

Object: `"define" length without (define ... )`

[Y 不动点组合子用在哪里？](https://www.zhihu.com/question/21099081/answer/18830200)

[Applicative-order Y Combinator](https://zhuanlan.zhihu.com/p/101872087)

```scheme
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
```

## What Is the Value of All of This?

**Interpreter**

```scheme
(define first
  (lambda (p)
    (car p)))

(define second
  (lambda (p)
    (car (cdr p))))

(define third
  (lambda (l)
    (car (cdr (cdr l)))))

; An entry is a pair of lists whose first list is a set. The two lists must be of equal length.

(define lookup-in-entry
  (lambda (name entry entry-f)
    (lookup-in-entry-help
      name
      (first entry)
      (second entry)
      entry-f)))

(define lookup-in-entry-help
  (lambda (name names values entry-f)
    (cond
      ((null? names) (entry-f name))
      ((eq? (car names) name) (car values))
      (else
        (lookup-in-entry-help
          name
          (cdr names)
          (cdr values)
          entry-f)))))

(lookup-in-entry
  'entree
  '((appetizer entree bevarage) (pate boeuf vin))
  (lambda (n) '()))

(lookup-in-entry
  'no-such-item
  '((appetizer entree bevarage) (pate boeuf vin))
  (lambda (n) '()))

; A table (also called an environment) is a list of entries.

(define lookup-in-table
  (lambda (name table table-f)
    (cond
      ((null? table) (table-f name))
      (else
        (lookup-in-entry
          name
          (car table)
          (lambda (name)
            (lookup-in-table
              name
              (cdr table)
              table-f)))))))

(lookup-in-table
  'dessert
  '(((entree dessert) (spaghetti spumoni))
    ((appetizer entree beverage) (food tastes good)))
  (lambda (n) '()))

(lookup-in-table
  'no-such-item
  '(((entree dessert) (spaghetti spumoni))
    ((appetizer entree beverage) (food tastes good)))
  (lambda (n) '()))


; Let's build our interpreter!

(define atom?
 (lambda (x)
    (and (not (pair? x)) (not (null? x)))))  

(define expression-to-action
  (lambda (e)
    (cond
      ((atom? e) (atom-to-action e))
      (else
        (list-to-action e)))))

(define atom-to-action
  (lambda (e)
    (cond
      ((number? e) *const)
      ((eq? e #t) *const)
      ((eq? e #f) *const)
      ((eq? e 'cons) *const)
      ((eq? e 'car) *const)
      ((eq? e 'cdr) *const)
      ((eq? e 'null?) *const)
      ((eq? e 'eq?) *const)
      ((eq? e 'atom?) *const)
      ((eq? e 'zero?) *const)
      ((eq? e 'add1) *const)
      ((eq? e 'sub1) *const)
      ((eq? e 'number?) *const)
      (else *identifier))))

(define list-to-action
  (lambda (e)
    (cond
      ((atom? (car e))
       (cond
         ((eq? (car e) 'quote) *quote)
         ((eq? (car e) 'lambda) *lambda)
         ((eq? (car e) 'cond) *cond)
         (else *application)))
      (else *application))))

(define value
  (lambda (e)
    (meaning e '())))

(define meaning
  (lambda (e table)
    ((expression-to-action e) e table)))

(define *const
  (lambda (e table)
    (cond
      ((number? e) e)
      ((eq? e #t) #t)
      ((eq? e #f) #f)
      (else
        (list 'primitive e)))))

; Example 1
(value 'car)

;(meaning car '())
;((expression-to-action car) car '())
;(atom-to-action car)
;(*const car '())
;(list 'primitive car)

(define *quote
  (lambda (e table)
    (text-of e)))

(define text-of second)

; Example 2
(value '(quote nothing))

;(meaning (quote nothing) '())
;((expression-to-action (quote nothing)) (quote nothing) '())
;(list-to-action (quote nothing))
;(*quote (quote nothing) '())
;(second (quote nothing))

(define *identifier
  (lambda (e table)
    (lookup-in-table e table initial-table)))

(define initial-table
  (lambda (name)
    (car '()))) ; let's hope we don't take this path

; Example 3
(meaning 'help '(((help) (1))))

;((expression-to-action help) help '(((help) (1))))
;(atom-to-action help)
;(*identifier help '(((help) (1))))
;(lookup-in-table help '(((help) (1))) initial-table)


(define *lambda
  (lambda (e table)
    (list 'non-primitive
          (cons table (cdr e)))))

; Example 4
(meaning '(lambda (x) (cons x y)) '(((y z) ((8) 9))))

;((expression-to-action (lambda (x) (cons x y))) (lambda (x) (cons x y)) (lambda (x) (cons x y)))
;(list-to-action (lambda (x) (cons x y)))
;(*lambda (lambda (x) (cons x y)) (((y z) ((8) 9))))
;(list 'non-primitive (cons (((y z) ((8) 9))) (cdr (lambda (x) (cons x y)))))


(define question-of first)
(define answer-of second)

(define evcon
  (lambda (lines table)
    (cond
      ((else? (question-of (car lines)))
       (meaning (answer-of (car lines)) table))
      ((meaning (question-of (car lines)) table)
       (meaning (answer-of (car lines)) table))
      (else
        (evcon (cdr lines) table)))))

(define else?
  (lambda (x)
    (cond
      ((atom? x) (eq? x 'else))
      (else #f))))

(define *cond
  (lambda (e table)
    (evcon (cond-lines-of e) table)))

(define cond-lines-of cdr)

; Example 5
(*cond '(cond (coffee klatsch) (else party)) '(((coffee) (#f)) ((klatsch party) (5 (6)))))

;(evcon ((coffee klatsch) (else party)) (((coffee) (#f)) ((klatsch party) (5 (6)))))
;(else? coffee)
;(meaning coffee (((coffee) (#f)) ((klatsch party) (5 (6)))))
;(evcon ((else party)) (((coffee) (#f)) ((klatsch party) (5 (6)))))
;(else? else)
;(meaning party (((coffee) (#f)) ((klatsch party) (5 (6)))))


(define evlis
  (lambda (args table)
    (cond
      ((null? args) '())
      (else
        (cons (meaning (car args) table)
              (evlis (cdr args) table))))))

(define *application
  (lambda (e table)
    (applyz
      (meaning (function-of e) table)
      (evlis (arguments-of e) table))))

(define function-of car)
(define arguments-of cdr)

(define primitive?
  (lambda (l)
    (eq? (first l) 'primitive)))

(define non-primitive?
  (lambda (l)
    (eq? (first l) 'non-primitive)))

(define applyz
  (lambda (fun vals)
    (cond
      ((primitive? fun)
       (apply-primitive (second fun) vals))
      ((non-primitive? fun)
       (apply-closure (second fun) vals)))))

(define apply-primitive
  (lambda (name vals)
    (cond
      ((eq? name 'cons)
       (cons (first vals) (second vals)))
      ((eq? name 'car)
       (car (first vals)))
      ((eq? name 'cdr)
       (cdr (first vals)))
      ((eq? name 'null?)
       (null? (first vals)))
      ((eq? name 'eq?)
       (eq? (first vals) (second vals)))
      ((eq? name 'atom?)
       (:atom? (first vals)))
      ((eq? name 'zero?)
       (zero? (first vals)))
      ((eq? name 'add1)
       (+ 1 (first vals)))
      ((eq? name 'sub1)
       (- 1 (first vals)))
      ((eq? name 'number?)
       (number? (first vals))))))

(define :atom?
  (lambda (x)
    (cond
      ((atom? x) #t)
      ((null? x) #f)
      ((eq? (car x) 'primitive) #t)
      ((eq? (car x) 'non-primitive) #t)
      (else #f))))

(define table-of first)
(define formals-of second)
(define body-of third)
(define extend-table cons)
(define new-entry list)

(define apply-closure
  (lambda (closure vals)
    (meaning
      (body-of closure)
      (extend-table (new-entry
                      (formals-of closure)
                      vals)
                    (table-of closure)))))

; Example 6
(*application '((lambda (x y) (eq? x y)) 1 2) '())

;(applyz (meaning '(lambda (x y) (eq? x y)) '()) (evlis '(1 2) '()))
;(applyz '(non-primitive (() (x y) (eq? x y))) '(1 2))
;(apply-closure '(() (x y) (eq? x y)) '(1 2))
;(meaning '(eq? x y) (cons (list '(x y) '(1 2)) '()))



; Comprehensive examples
(value '(add1 6))
(value '(quote (a b c)))
(value '(car (quote (a b c))))
(value '(cdr (quote (a b c))))
(value
  '((lambda (x)
      (cons x (quote ())))
    (quote (foo bar baz))))
(value
  '((lambda (x)
      (cond
        (x (quote true))
        (else
          (quote false))))
    #t))
```