;problem 1

;a

(define (accumulate combiner null-value term a next b)
  (if (< a b)
      (combiner (term a) (accumulate combiner null-value term (next a) next b))
      (term a))
)

;b

(define (catalan n)
  (define (term k) (/ (+ n k) k))
  (define (next i) (+ i 1))
  (define (combiner a b) (* a b))
  (if (> n 1)
      (accumulate combiner (term n) term 2 next n)
      1)
)

;c

(define (leibniz-pi n)
  (define (term k)
    (if (= k 0) 1
        (* (expt -1 k) (/ 1 (+ (* 2 k) 1)))))
  (define (next i) (+ i 1))
  (define (combiner a b) (+ a b))
  (if (= n 0)
      0
      (* 4 (accumulate combiner (term n) term 0 next (- n 1))))
)

;d

(define (accumulate-tr combiner null-value term a next b)
  (define (help c d total)
    (if (< c d)
        (help (+ c 1) d (combiner (term c) total))
        (combiner (term c) total))
  )
  (if (= a b) (term a)
      (help (+ a 1) b (term a)))
)

;e

(define (fact n)
  (define (combiner a b) (* a b))
  (define (term k) k)
  (define (next i) (+ i 1))
  (if (or (= n 0) (= n 1)) 1
      (accumulate-tr combiner 1 term 1 next n))
)

;f

(define (e-to-x x n)
  (define (combiner a b) (+ a b))
  (define (term k) (/ (expt x k) (fact k)))
  (define (next i) (+ i 1))
  (if (= n 0) 1
      (accumulate-tr combiner (term n) term 0 next n))
)


;problem 2

;a

(define (encode p)
  (if (= (max (car p) (cdr p)) (car p))
      (+ (expt (car p) 2) (car p) (cdr p))
      (+ (expt (cdr p) 2) (car p)))
)

;b

(define (decode z)
  (if (< (- z (expt (floor (sqrt z)) 2)) (floor (sqrt z)))
      (cons (- z (expt (floor (sqrt z)) 2)) (floor (sqrt z)))
      (cons (floor (sqrt z)) (- z (expt (floor (sqrt z)) 2) (floor (sqrt z)))))
)


;problem 3

;a

(define (sub-complex c d)
  (let ((a (car c))
        (b (cdr c))
        (c (car d))
        (d (cdr d)))
    (cons (- a c) (- b d)))
)

;b

(define (div-complex c d)
  (let ((a (car c))
        (b (cdr c))
        (c (car d))
        (d (cdr d)))
    (cons (/ (+ (* a c) (* b d)) (+ (expt c 2) (expt d 2)))
          (/ (- (* b c) (* a d)) (+ (expt c 2) (expt d 2)))))
)


;problem 4

;a

;i

(define (sum-quadratic-roots a b c)
  (let ((z (div-complex b a)))
    (cons (* -1 (car z)) (* -1 (cdr z))))
)

;ii

(define (prod-quadratic-roots a b c)
  (div-complex c a)
)

;b

;i

(define (sum-cubic-roots a b c d)
  (let ((z (div-complex b a)))
    (cons (* -1 (car z)) (* -1 (cdr z))))
)

;ii

(define (sum-pairs-cubic-roots a b c d)
  (div-complex c a)
)

;iii

(define (prod-cubic-roots a b c d)
  (let ((z (div-complex d a)))
    (cons (* -1 (car z)) (* -1 (cdr z))))
)