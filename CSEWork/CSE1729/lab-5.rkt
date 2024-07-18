;problem 1

(define (square-pair i)
  (cons i (* i i))
)

;problem 2

(define (rev p)
  (define z (cons (cdr p) (car p)))
  z
)

;problem 3

;a

(define (c->p p)
  (let ((r (sqrt (+ (expt (car p) 2) (expt (cdr p) 2))))
        (theta (atan (/ (cdr p) (car p)))))
    (cons r theta))
)

;b

(define (p->c p)
  (let ((x (* (car p) (cos (cdr p))))
        (y (* (car p) (sin (cdr p)))))
    (cons x y))
)

;problem 4

(define (y p1 p2)
  (define (mxb x)
    (let ((m (/ (- (cdr p2) (cdr p1)) (- (car p2) (car p1)))))
      (let ((b (- (cdr p1) (* m (car p1)))))
        (+ (* m x) b))))
  mxb
)