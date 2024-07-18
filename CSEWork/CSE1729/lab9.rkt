(define (create-heap v H1 H2)
  (list v H1 H2)
)

(define (root H) (car H))
(define (left H) (cadr H))
(define (right H) (caddr H))

(define (heap-insert f x H)
  (cond ((null? H) (create-heap x '() '()))
        ((f x (root H))
         (create-heap x
                      (right H)
                      (heap-insert f (root H) (left H))))
        (else (create-heap (root H)
                           (right H)
                           (heap-insert f x (left H))))))

(define (combine f Ha Hb)
  (cond ((null? Ha) Hb)
        ((null? Hb) Ha)
        ((f (root Ha) (root Hb))
         (create-heap (root Ha) Hb (combine f (left Ha) (right Ha))))
        (else
         (create-heap (root Hb) Ha (combine f (left Hb) (right Hb)))))
)

(define (heap-remove f H)
  (combine f (left H) (right H))
)

;a

(define (equalize-heaps heap-pair)
  (cond ((> (- (caar heap-pair) (cadr heap-pair)) 1)
         (equalize-heaps (cons (cons (- (caar heap-pair) 1) (heap-remove > (cdar heap-pair)))
                               (cons (+ (cadr heap-pair) 1) (heap-insert < (root (cdar heap-pair)) (cddr heap-pair))))))
        ((> (- (cadr heap-pair) (caar heap-pair)) 1)
         (equalize-heaps (cons (cons (+ (caar heap-pair) 1) (heap-insert > (root (cddr heap-pair)) (cdar heap-pair)))
                               (cons (- (cadr heap-pair) 1) (heap-remove < (cddr heap-pair))))))
        (else heap-pair)))

;b

(define (add-number x heap-pair)
  (if (< x (car (cdr (car heap-pair))))
      (equalize-heaps (cons (cons (+ (caar heap-pair) 1) (heap-insert > x (cdar heap-pair)))
                            (cons (cadr heap-pair) (cddr heap-pair))))
      (equalize-heaps (cons (cons (caar heap-pair) (cdar heap-pair))
                      (cons (+ (cadr heap-pair) 1) (heap-insert < x (cddr heap-pair)))))))

;c

(define (get-median heap-pair)
  (let ((new-pair (equalize-heaps heap-pair)))
    (let ((h1 (car heap-pair))
          (h2 (cdr heap-pair)))
      (if (> (car h1) (car h2))
          (car (cdr h1))
          (if (= (car h1) (car h2))
              (/ (+ (car (cdr h1)) (car (cdr h2))) 2)
              (car (cdr h2))))
    )
  )
)