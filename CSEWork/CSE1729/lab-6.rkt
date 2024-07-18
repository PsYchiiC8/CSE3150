;problem 1

;a

(define (list-at l i)
  (if (= i 0)
      (car l)
      (list-at (cdr l) (- i 1)))
)

;b

(define (selSort l)
  (define (smallest l)
    (define (smaller a b)
      (if (< a b) a
          b))
    (if (null? (cdr l))
        (car l)
        (smaller (car l) (smallest (cdr l)))))
  (define (remove v l)
    (if (null? l) l
        (if (equal? v (car l))
            (cdr l)
            (cons (car l) (remove v (cdr l))))))
  (if (null? l)
      '()
      (let* ((first (smallest l))
            (rest (remove first l)))
        (cons first (selSort rest)))))

(define (find-length l)
  (if (null? l) 0
      (+ 1 (find-length (cdr l))))
)

(define (list-median l)
  (let ((len-l (find-length l))
        (l2 (selSort l)))
    (cond ((= (modulo len-l 2) 0)
          (/ (+ (list-at l2 (/ len-l 2)) (list-at l2 (- (/ len-l 2) 1))) 2))
          ((= len-l 1)
           (car l2))
          (#t
          (list-at l2 (floor (/ len-l 2))))))
)


;problem 2

;a

(define (explode x)
  (define (exp num lst)
    (if (> (floor (/ num 10)) 0)
        (exp (floor (/ num 10)) (append lst (list (modulo num 10))))
        (append lst (list (modulo num 10)))))
  (reverse (exp x '()))
)

;b

(define (implode l)
  (define (help x lst)
    (if (null? lst) x
        (help (+ (* x 10) (car lst)) (cdr lst)))
  )
  (help 0 l)
)

;c

(define (sum x l)
  (if (null? (cdr l)) (+ x (car l))
      (sum (+ x (car l)) (cdr l)))
)

(define (has-property x)
  (let* ((x2 (explode x))
         (x3 (sum 0 x2))
         (x4 (explode x3))
         (x5 (implode (reverse x4)))
         (x6 (* x3 x5)))
    (= x x6))
)

;d

(define (sequence x)
  x)

(define (test x)
  (has-property x))

(define (find sequence test n)
  (define (help x k)
    (if (and (< k n) (test (sequence x)))
        (help (+ x 1) (+ k 1))
        (if (and (< k n) (not (test (sequence x))))
            (help (+ x 1) k)
            x))
  )
  (help 0 0)
)

