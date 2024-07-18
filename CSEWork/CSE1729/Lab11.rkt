(define (head s) (car s))
(define (rest s) (force (cdr s)))

;problem 1

;a

(define (lucas-stream)
  (define (help now next)
    (cons now (delay (help next (+ now next))))
  )
  (help 1 3)
)

;b

(define (lucas-pseudoprime i)
  (define (help k lstream)
    (if (= k 1)
        (head lstream)
        (help (- k 1) (rest lstream))))
  (let ((ith (help i (lucas-stream))))
    (= (modulo (- ith 1) i) 0))
)


;problem 2

;a

(define (ll-stream)
  (define (help i)
    (cons i (delay (help (- (* i i) 2))))
  )
  (help 4)
)

;b

(define (ll-test-stream c)
  (define (help i)
    (cons i (delay (help (modulo (- (* i i) 2) c))))
  )
  (help 4)
)


;problem 3

(define (mprime? p)
  (define (help lstream i)
    (if (= i 2)
        (= (head lstream) 0)
        (help (rest lstream) (- i 1)))
  )
  (help (ll-test-stream (- (expt 2 p) 1)) p)
)
