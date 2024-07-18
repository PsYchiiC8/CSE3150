;problem 1

(define  (geom-series-np2 n)
  (if (= n 0)
      1
      (+ (/ 1 (expt 2 n)) (geom-series-np2 (- n 1))))
)


;problem 2

(define (num-digits n)
  (if (< n 10)
      1
      (+ 1 (num-digits (floor (/ n 10)))))
)

;problem 3

;part a

(define (a n)
  (if (= n 0)
      1
      (* 2 (a (- n 1))))
)

;part b

(define (num-ancestors n)
  (if (= n 0)
      0
      (+ (a n) (num-ancestors (- n 1))))
)

;problem 4

(define (factorial n)
  (if (or (= n 0) (= n 1))
      1
      (* n (factorial (- n 1))))
)

(define (n-choose-k n k)
  (if (or (< n k) (< k 0))
         0
        (/ (factorial n) (* (factorial (- n k)) (factorial k))))
)

;problem 5

(define (pascals-triangle n k)
  (cond ((or (< k 0) (< n k))
         0)
        ((and (= n 0) (= k 0))
         1)
        (#t
         (+ (pascals-triangle (- n 1) k) (pascals-triangle (- n 1) (- k 1))))
  )
)
