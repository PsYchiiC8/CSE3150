;problem 1

(define (merge l1 l2)
  (cond ((null? l2) l1)
        ((null? l1) l2)
        ((<= (car l1) (car l2))
         (cons (car l1) (merge (cdr l1) l2)))
        ((< (car l2) (car l1))
         (cons (car l2) (merge l1 (cdr l2)))))
)


;problem 2

(define (split l)
  (if (null? l)
      (list '() '())
      (if (null? (cdr l))
          (list l '())
          (let ((rest (split (cdr (cdr l)))))
            (list (cons (car l) (car rest))
                  (cons (car (cdr l)) (car (cdr rest))))))))

(define (mergeSort l)
  (if (null? l)
      '()
      (if (null? (cdr l))
          l
          (let ((s (split l)))
            (let ((a (car s)) (b (car (cdr s))))
              (merge (mergeSort a) (mergeSort b))))))
)


;problem 3

(define (ins num lst)
  (define (help l-new l)
    (if (null? l) (append l-new (list num))
        (if (<= num (car l))
            (append (append l-new (list num)) l)
            (help (append l-new (list (car l))) (cdr l))))
  )
  (help '() lst)
)


;problem 4

(define (insSort l)
  (define (help l-new lst)
    (if (not (null? lst))
        (help (ins (car lst) l-new) (cdr lst))
        l-new)
  )
  (help '() l)
)


;problem 5

;a

(define (fold-right op initial sequence)
  (define (help seq)
    (if (null? seq) initial
        (op (car seq) (help (cdr seq))))
  )
  (op (car sequence) (help (cdr sequence)))
)

;b

(define (fold-left op initial sequence)
  (if (null? sequence) initial
      (fold-left op (op initial (car sequence)) (cdr sequence)))
)

;c

(define (my-map p sequence)
  (fold-right (lambda (x y) (cons (p x) y)) '() sequence)
)

;d

(define (my-append seq1 seq2)
  (fold-right cons seq2 seq1)
)

;e

(define (my-length sequence)
  (if (null? sequence) 0
      (fold-right (lambda (x y) (+ 1 y)) 0 sequence))
)

;f

(define (reverse-r sequence)
  (if (null? sequence) '()
      (fold-right (lambda (x y) (append y (list x))) '() sequence))
)

;g

(define (reverse-l sequence)
  (fold-left (lambda (x y) (append (list y) x)) '() sequence))

;h

(define (horner-eval x coefficient-list)
  (define (term y coeff)
    (+ (* coeff x) y)
  )
  (fold-right term 0 coefficient-list)
)


;problem 6

(define (prime? n)
  (define (divisor? k) (= 0 (modulo n k)))
  (define (divisors-upto k)
    (and (> k 1)
         (or (divisor? k) (divisors-upto (- k 1)))))
  (and (> n 1)
       (not (divisors-upto (- n 1)))))

(define (find sequence test n)
  (define (find-aux x found)
    (let ((fx (sequence x)))
       (if (test fx)
           (if (= (+ found 1) n)
               fx
               (find-aux (+ x 1) (+ found 1)))
           (find-aux (+ x 1) found)))
  )
  (find-aux 1 0)
)

;a

(define (explode x)
  (if (< x 10)
      (list x)
      (append (explode (floor (/ x 10))) (list (- x (* 10 (floor (/ x 10)))))))
)

(define (implode l)
  (define (helper l n)
    (if (null? l)
        0
        (+ (* (car l) (expt 10 n))
           (helper (cdr l) (+ n 1)))))
  (helper (reverse l) 0)
)

;i

(define (left-truncatable-prime? p)
  (cond ((< p 10) (prime? p))
        ((= 0 (cadr (explode p))) #f)
        (#t
         (and (prime? p) (left-truncatable-prime? (implode (cdr (explode p)))))))
)


;ii

(define (nth-left-trunc-prime n)
  (find (lambda (x) x) left-truncatable-prime? n)
)

;b

;i

(define (right-truncatable-prime? p)
  (define (remove-last lst)
    (if (null? (cdr lst)) '()
        (cons (car lst) (remove-last (cdr lst))))
  )
  (cond ((< p 10) (prime? p))
        (#t
         (and (prime? p) (right-truncatable-prime? (implode (remove-last (explode p)))))))
)

;ii

(define (nth-right-trunc-prime n)
  (find (lambda (x) x) right-truncatable-prime? n)
)


;c

;i

(define (two-sided-prime? p)
  (and (left-truncatable-prime? p) (right-truncatable-prime? p))
)

;ii

(define (nth-two-sided-prime n)
  (find (lambda (x) x) two-sided-prime? n)
)