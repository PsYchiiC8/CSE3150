;problem 1

;a
(define (fizzbuzz x)
  (if (and (not (= (modulo x 3) 0)) (not (= (modulo x 5) 0)))
      x
      (if (= 0 (modulo x 3))
          (if (= 0 (modulo x 5))
              "fizzbuzz"
              "fizz"
          )
          "buzz"
      )
  )
)


;b

(define (fizz x)
  (= (modulo x 3) 0)
)

(define (buzz x)
  (= (modulo x 5) 0)
)

(define (fizzbuzz2 x)
  (cond ((and (not (fizz x)) (not (buzz x)))
             x)
        ((and (fizz x) (buzz x))
             "fizzbuzz")
        ((fizz x)
             "fizz")
        ((buzz x)
             "buzz")
  )
)


;problem 2

(define (piecewise x)
  (define pi 3.142)
  (cond ((> x (* pi 2))
         (- x (* pi 2)))
        ((<= (* -1 pi) x)
         (sin x))
        ((< x (* -1 pi))
         (- (* -1 x) pi)))
)

;problem 3

(define (inc x) (+ x 1))

(define (dec x) (- x 1))

(define (add n m)
  (if (> n 0)
      (add (dec n) (inc m))
      m
  )
)

;problem 4

(define (mult n m)
  (cond ((> n 1)
        (add m (mult (dec n) m)))
        ((= n 0)
         0)
        ((= n 1)
        m)
  )
)

;problem 5

(define (power b n)
  (cond ((> n 2)
         (mult b (power b (dec n))))
        ((= n 0)
         1)
        ((= n 2)
         (mult b b))
        ((= n 1)
         b)
  )
)

;problem 6

(define (raise x n)
  (cond ((> (floor n) 2)
         (mult x (raise x (dec n))))
        ((= n 0)
         1)
        ((= n 2)
         (mult x x))
        ((= n 1)
         x)))

;problem 7

(define (pmult x y)
  (if (= x 0)
      0
      (if (= x 1)
          y
          (if (= (modulo x 2) 0)
              (pmult (floor (/ x 2)) (* y 2))
              (+ y (pmult (floor (/ x 2)) (* y 2))))
          )
      )
)

;problem 8

;part 1

(define (sumEven n)
  (if (= n 0)
      0
      (if (= (modulo n 2) 0)
          (+ n (sumEven (- n 1)))
          (sumEven (- n 1))))
)

;part 2

(define (sumOdd n)
  (if (or (= n 1) (= n 0))
      n
      (if (= (modulo n 2) 1)
          (+ n (sumOdd (- n 1)))
          (sumOdd (- n 1))))
          
)

;problem 9

(define (h-product k)
  (if (= k 1)
      1
      (* (- 1 (/ 1 k)) (h-product (- k 1))))
)

;problem 10

(define (divides a b)
  (= 0 (modulo b a))
)

(define (divisors-upto n k)
  (cond ((or (= k 0) (= n 0))
         0)
        ((= k 1)
         1)
        ((divides k n)
            (+ 1 (divisors-upto n (- k 1))))
        ((not (divides k n))
             (divisors-upto n (- k 1)))
  )
)

(define (divisors n)
  (divisors-upto n n))

;problem 11

(define (subfact n)
  (cond ((= n 0)
         1)
        ((= n 1)
         0)
        ((> n 1)
         (* (- n 1) (+ (subfact (- n 1)) (subfact (- n 2)))))
  )
)

;problem 12

(define (factorial n)
  (if (or (= n 0) (= n 1))
      1
      (* n (factorial (- n 1))))
)

(define (new-cos x n)
  (if (= n 0)
      1
      (+ (/(* (expt -1 n) (expt x (* n 2))) (factorial (* n 2))) (new-cos x (- n 1))))
)
