;problem 1

(define (pell n)
  (cond ((= n 0)
         0)
        ((= n 1)
         1)
        (#t
         (+ (* 2 (pell (- n 1))) (pell (- n 2)))))
)

(define (find-pell n)
  (define (num k n)
    (if (> (pell k) n)
        (pell (- k 1))
        (num (+ k 1) n)))
  (num 0 n)
)


(define (comp-pell n)
  (if (or (= n 0) (= n 1)) 2
      (+ (* 2 (comp-pell (- n 1))) (comp-pell (- n 2))))
)


(define (sqrt-2-approx n)
  (if (= n 0)
      0
      (/ (/ (comp-pell n) 2) (pell n)))
)


;problem 2

(define (viete-terms n)
  (if (= n 0)
      0
      (sqrt (+ 2 (viete-terms (- n 1)))))
)

      
(define (viete n)
  (if (= n 0)
      1
      (* (/ (viete-terms n) 2) (viete (- n 1))))
)


;problem 3

(define (new-sqrt x n)
  (define (main n)
    (cond ((= n 0)
           0)
          (#t
           (/ (- x 1) (+ 2 (main (- n 1)))))))
  (+ (main n) 1)
)


;problem 4

(define (m91 n)
  (cond ((> n 100)
         (- n 10))
        ((<= n 100)
         (m91 (m91 (+ n 11)))))
)


;problem 5

(define (iradius A B C)
  (let ((s (/ (+ A B C) 2)))
    (sqrt (/ (* (- s A) (- s B) (- s C)) s)))
)


;problem 6

(define (heron a b c)
  (let ((s (/ (+ a b c) 2)))
    (sqrt (* s (- s a) (- s b) (- s c)))
  )
)

(define (heron2 a b c)
  (let ((s (/ (+ a b c) 2)))
    (let ((sa (- s a))
          (sb (- s b))
          (sc (- s c)))
      (sqrt (* s sa sb sc)))
  )
)