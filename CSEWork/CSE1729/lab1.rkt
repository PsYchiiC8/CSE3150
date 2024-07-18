;problem 1

(define (usd-to-euro dollars)
  (* dollars .82))

(define (euro-to-yen euros)
  (* euros 126.01))

(define (usd-to-yen dollars)
  (euro-to-yen (usd-to-euro dollars)))


;problem 2

(define e 2.71828)

(define (tanh x)
  (/ (- (expt e (* 2 x)) 1) (+ (expt e (* 2 x)) 1)))


;problem 3

(define (det2x2 a b c d)
  (- (* a d) (* b c)))

(define  (invertible? a b c d)
 (not (= (det2x2 a b c d) 0))
)

(define (prod-inv-direct? a1 b1 c1 d1 a2 b2 c2 d2)
  (define a (+ (* a1 a2) (* b1 c2)))
  (define b (+ (* a1 b2) (* b1 d2)))
  (define c (+ (* c1 a2) (* d1 c2)))
  (define d (+ (* c1 b2) (* d1 d2)))

  (not (= (det2x2 a b c d) 0))
)

(define (prod-inv-indirect? a1 b1 c1 d1 a2 b2 c2 d2)
  (not (= (* (det2x2 a1 b1 c1 d1) (det2x2 a2 b2 c2 d2)) 0))
)
