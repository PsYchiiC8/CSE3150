;problem 1

(define (zip a b)
  (define (help-zip lst an bn)
    (if (null? an)
        lst
        (help-zip (append lst (list (cons (car an) (car bn)))) (cdr an) (cdr bn))))
  (help-zip '() a b)
)


;problem 2

(define (unzip l)
  (define (help-unzip la lb ln)
    (if (null? ln)
        (cons la lb)
        (help-unzip (append la (list (car (car ln)))) (append lb (list (cdr (car ln)))) (cdr ln))))
  (help-unzip '() '() l)
)


;problem 3

;a

(define (list-sum lst)
  (define (total tot l)
    (if (null? l)
        tot
        (total (+ tot (car l)) (cdr l))))
  (total 0 lst)
)

;b

(define (len lst)
  (if (null? lst) 0
      (+ 1 (len (cdr lst))))
)

(define (average X)
  (/ (list-sum X) (len X))
)

;c

(define (var-map X)
  (let ((avg (average X)))
    (define (diff a) (expt (- avg a) 2))
    (map diff X))
)

;d

(define (stdev l)
  (sqrt (* (/ 1 (len l)) (list-sum (var-map l))))
)

;e

(define (map2 f X Y)
  (define (help-map lst Xn Yn)
    (if (null? Xn) lst
        (help-map (append lst (list (f (car Xn) (car Yn)))) (cdr Xn) (cdr Yn)))
  )
  (help-map '() X Y)
)

;f

(define (var-map2 X)
  (let ((avg (average X)))
    (define (diff a) (- a avg))
    (map diff X))
)

(define (covar-elements X Y)
  (let ((map-x (var-map2 X))
        (map-y (var-map2 Y)))
    (define (help-covar lst Xn Yn)
      (if (null? Xn) lst
          (help-covar (append lst (list (* (car Xn) (car Yn)))) (cdr Xn) (cdr Yn)))
    )
    (help-covar '() map-x map-y))
)

;g

(define (pearson X Y)
  (/ (* (/ 1 (len X)) (list-sum (covar-elements X Y))) (* (stdev X) (stdev Y)))
)


;problem 4

;a

(define (best-fit X Y)
  (let* ((a (* (pearson X Y) (/ (stdev Y) (stdev X))))
         (b (- (average Y) (* a (average X)))))
    (cons a b))
)

;b

(define (best-fit-fn pX pY)
  (let* ((a (* (pearson pX pY) (/ (stdev pY) (stdev pX))))
         (b (- (average pY) (* a (average pX)))))
    (lambda (x)
      (+ (* a x) b)))
)