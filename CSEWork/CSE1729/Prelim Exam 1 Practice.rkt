;problem 1

;a

(define (chord-length theta)
  (* 2 (sin (/ theta 2)))
)

;b

(define (iradius A B C)
  (let ((S (/ (+ A B C) 2)))
    (sqrt (/ (* (- S A) (- S B) (- S C)) S)))
)

;c

(define (harmonic n)
  (if (> n 1)
      (+ (/ 1 n) (harmonic (- n 1)))
      1)
)

;d

(define (reciprocals n)
  (if (and (prime? n) (> n 1))
      (+ (/ 1 n) (reciprocals (- n 1)))
      (if (< n 2)
          0
          (reciprocals (- n 1))))
)


;problem 2

;a

(define (improve g)
  (/ (+ (* g g) 1) (- (* 2 g) 1))
)

;b

(define (phi-help k n an)
  (if (< k n)
      (phi-help (+ k 1) n (improve an))
      an)
)

(define (phi-approximant n)
  (phi-help 0 n 1)
)

;c

(define (absolute x)
  (if (< x 0)
      (* x -1)
      x))

(define (phi-iterate guess tol)
  (let ((guess2 (- (* guess guess) guess 1)))
    (if (<= (absolute (- guess2 (improve guess))) tol)
        guess
        (phi-iterate (+ guess 1) tol)))
)

(define (phi-approx accuracy)
  (phi-iterate 1 accuracy)
)

;d

;a prgoram is tail recursive if there is no new environment created with each successive call to the function
;part c was not completed, so......


;problem 3

;a- not done

;The program stops calling itself when it reaches F(n - 2) and F(n - 3). The program needs to continue on for a little bit longer before it stops calling itself. This can be done by adding

;b
;in g, the input is 110 and is labeled y, x is taken from (f x) which would be 1000 so it would take 1000 + 110 and give 1110

;c
;240, y taken from first let, z taken from second(12, "aka y" from second let)

;d
;can definitely get all three, the third one might take more than an hour or never finish
;might never evaluate, let gets evaluated first, will always be calling itself until memory runs out
;probably the fastest and mostly likely to get it done, maybe not 500(it is a large number), but most of the others will likely work


;problem 4

;a

(define (test-upto n k)
  (if (< n k)
      (if (= (* n n) k)
          #t
          (test-upto (+ n 1) k))
      #f)
)

(define (perfect-square? n)
  (if (or (= n 0) (= n 1))
      #t
      (test-upto 1 n))
)

;b

(define (pell-solution n x)
  (if (= n 0)
      #f
      (let ((p (/ (- (* x x) 1) n)))
        (perfect-square p)))
)

;c

(define (help-pell n x)
  (if (pell-solution n x)
      x
      (help-pell n (+ n 1)))
)

(define (pell-solve n)
  (help-pell n 1)
)