;problem 1

(define (sum term a next b)
  (if (> a b)
      0
      (+ (term a)
         (sum term (next a) next b)))
)

(define (harmonic n)
  (define (term a) (/ 1 a))
  (define (next a) (+ 1 a))
  (sum term 1 next n)
)


;problem 2

;a

(define (product term a next b)
  (if (> a b)
      1
      (* (term a) (product term (next a) next b)))
)

;b

(define (wallis-pi n)
  (define (term a)
    (* (/ (* 2 a) (- (* 2 n) 1))
       (/ (* 2 a) (+ (* 2 n) 1))))
  (define (next a) (+ a 1))
  (product term 1 next n)
)


;problem 3

(define (frac-sum f g n)
  (if (= (g n) 0)
      0
      (+ (/ (f n) (g n)) (/ (f (* n -1)) (g (* n -1))) (frac-sum f g (- n 1))))
)


;problem 4

;a

(define (der f h)
  (define (helpy x)
    (/ (- (f (+ x h)) (f x)) h)
  )
  helpy
)

;b

(define (der-n f n h)
  (if (> n 0)
      (der-n (der f h) (- n 1) h)
      f)
)


;problem 5

(define (newton f x n)
  (define new-func (der f .01))
  (define (help-newton x i)
    (let ((new-x (- x (/ (f x) (new-func x)))))
      (if (> i 0)
          (help-newton new-x (- i 1))
          x))
  )
  (help-newton x n)
)


;problem 6

(define (sum-term term a b)
  (if (<= a b)
      (+ (term a) (sum-term term (+ a 1) b))
      0)
)

(define (simpson-integrate f a b n)
  (let ((h (/ (- b a) n)))
    (define (y k)
      (f (+ a (* k h))))
    (define (term k)
      (cond ((or (= k 0) (= k n)) (y k))
            ((= (modulo k 2) 0) (* 2 (y k)))
            (#t (* 4 (y k)))))
    (* (/ h 3) (sum-term term 0 n)))
)

