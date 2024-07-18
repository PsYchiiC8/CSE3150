(define (maketree v left-tree right-tree)
  (list v left-tree right-tree))
(define (value T) (car T))
(define (left T) (cadr T))
(define (right T) (caddr T))

;problem 1

;a

(define (listmax L)
  (if (null? (cdr L))
      (car L)
      (max (car L) (listmax (cdr L))))
)

;b

(define (filter L k)
  (define (help lst-new lst)
    (if (null? lst) lst-new
        (if (< (car lst) k)
            (help (append lst-new (list (car lst))) (cdr lst))
            (help lst-new (cdr lst))))
  )
  (help '() L)
)

;c

(define (treesize T)
  (if (null? T) 0
      (+ 1 (treesize (left T)) (treesize (right T))))
)


;problem 2

;a


;b

;this allows the tree to remain balanced and not have a lot on one side and nothing on the other

;c


;d


;problem 3

