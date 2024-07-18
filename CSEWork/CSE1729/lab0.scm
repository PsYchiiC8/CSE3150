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
  (cond ((> n 1)
         (power (dec n) (mult b b)))
        ((= n 0)
         1)
        ((= n 1)
         b)
  )
)

(display (power 2 3))