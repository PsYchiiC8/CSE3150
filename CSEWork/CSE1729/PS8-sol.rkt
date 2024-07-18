(define (make-tree value left right) (list value left right))
(define (value tree) (car tree))
(define (left tree) (cadr tree))
(define (right tree) (caddr tree))

;problem 1

(define (tree-map T f)
  (if (null? T) '()
      (make-tree (f (value T)) (tree-map (left T) f) (tree-map (right T) f)))
)

;problem 2

(define (tree-equal? T1 T2)
  (cond ((and (null ? T1) (null? T2)) #t)
        ((or (null? T1) (null? T2)) #f)
        (else (and (eq? (value T1) (value T2)) (tree-equal? (left T1) (left T2)) (tree-equal? (right T1) (right T2)))))
)


;problem 3

(define (insert element T)
  (cond ((null? T) (make-tree element '() '()))
        ((< element (value T)) (make-tree (value T) (insert element (left T)) (right T)))
        (else (make-tree (value T) (left T) (insert element (right T)))))
)

(define (insert-list L T)
  (if (null? L) T
      (insert-list (cdr L) (insert (car L) T)))
)

(define (sort-extract T)
  (if (null? T) '()
      (append (sort-extract (left T)) (list (value T)) (sort-extract (right T))))
)

(define (tree-sort elements)
  (sort-extract (insert-list elements '()))
)

;problem 4

(define (delete-value v T)
  (define (leaf? T) (and (null? (left T))
                         (null? (right T))))
  (define (tree-max T)
    (if (null? (right T))
        (value T)
        (max (value T)
             (tree-max (right T)))))
  (cond ((null? T) '())
        ((< v (value T)) (make-tree (value T)
                                    (delete-value v (left T))
                                    (right T)))
        ((> v (value T)) (make-tree (value T)
                                    (left T)
                                    (delete-value v (right T))))
        ((null? (left T)) (right T))
        (else (make-tree (tree-max (left T))
                         (delete-value (tree-max (left T))  (left T))
                         (right T))))
)

;problem 5

(define (arithvalue T)
  (cond ((eq? (value T) #\+)
         (+ (arithvalue (left T)) (arithvalue (right T))))
        ((eq? (value T) #\*)
         (* (arithvalue (left T)) (arithvalue (right T))))
        ((eq? (value T) #\-)
         (- 0 (arithvalue (left T))))
        ((eq? (value T) #\/)
         (/ 1 (arithvalue (left T))))
        (#t
         (value T)))
)

;problem 6

(define (prepare x)
  (cond ((number? x) (number->string x))
        ((char? x) (string x)))
)

;a

(define (arith-prefix T)
  (define (help T)
    (if (null? T) ""
        (string-append (value T) (help (left T)) (help (right T))))
  )
  (help (tree-map T prepare))
)

;b

(define (arith-postfix T)
  (define (help T)
    (if (null? T) " "
        (string-append (help (left T)) (help (right T)) (value T )))
  )
  (help (tree-map T prepare))
)

;c

(define (arith-infix T)
  (cond ((eq? (value T) #\+)
         (string-append "(" (arith-infix (left T)) "+"
                        (arith-infix (right T)) ")"))
        ((eq? (value T) #\*)
         (string-append "(" (arith-infix (left T)) "*"
                        (arith-infix (right T)) ")"))
        ((eq? (value T) #\-)
         (string-append "-(" (arith-infix (left T)) ")"))
        ((eq? (value T) #\/)
         (string-append "/(" (arith-infix (left T)) ")"))
        (#t
         (number->string (value T))))
)