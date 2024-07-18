
(define (create-heap v H1 H2)
  (list v H1 H2)
)

(define (h-min  H) (car H))
(define (left H) (cadr H))
(define (right H) (caddr H))
      

;a

(define (heap-insert f x H)
  (cond ((null? H) (create-heap x '() '()))
        ((f x (h-min H))
         (create-heap x (right H) (heap-insert f (h-min H) (left H))))
        ((f (h-min H) x)
        (create-heap (h-min H) (right H) (heap-insert f x (left H)))))
)

;b

(define (combine f Ha Hb)
  (cond ((null? Ha) Hb)
        ((null? Hb) Ha)
        ((f (h-min Ha) (h-min Hb))
         (create-heap (h-min Ha) Hb (combine f (left Ha) (right Ha))))
        (else
         (create-heap (h-min Hb) Ha (combine f (left Hb) (right Hb)))))
)

;c

(define (empty? H)
  (null? H)
)

;d

(define (heap-remove f H)
  (combine f (left H) (right H))
)