;problem 1

(define (windchill W F)
  (let ((x (sqrt W)))
    (+ 1.05 (* 0.93 F) (* -3.65 W) (* 3.62 x) (* 0.103 F x) (* 0.0439 (expt W 2))))
)


;problem 2

(define (pressure h)
  (let ((p0 101325)
        (L 0.0065)
        (T0 288.15)
        (g 9.80665)
        (M 0.0289644)
        (R 8.31447))
    (* p0 (expt (- 1 (/ (* L h) T0)) (/ (* g M) (* R L)))))
)


;problem 3

(define (compose f g)
  (define (compose2 x)
    (f (g x)))
  compose2
)


;problem 4

(define (repeated f n)
  (cond ((= n 1)
        f)
        (#t
          (compose f (repeated f (- n 1)))))
)