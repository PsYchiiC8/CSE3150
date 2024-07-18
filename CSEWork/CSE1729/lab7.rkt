(define (make-tree value left right)
  (list value left right))

(define (value T) (car T))
(define (right T) (caddr T))
(define (left T) (cadr T))

;problem 1

(define (tree-size T)
  (if (null? T)
      0
      (+ 1 (tree-size (left T)) (tree-size (right T))))
)

;problem 2

(define (tree-depth T)
  (if (null? T)
      -1
      (+ 1 (max (tree-depth (left T))
                (tree-depth (right T)))))
)

;problem 3

(define (count-pred P tree)
  (if (null? tree) 0
      (if (P (value tree))
          (+ 1 (count-pred P (left tree)) (count-pred P (right tree)))
          (+ (count-pred P (left tree)) (count-pred P (right tree)))))
)


;problem 4

(define (count-one-child T)
  (let ((child-l (left T))
        (child-r (right T)))
    (cond ((and (null? child-l) (null? child-r))
           0)
          ((and (not (null? child-l)) (not (null? child-r)))
           (+ (count-one-child child-l) (count-one-child child-r)))
          ((null? child-l)
           (+ 1 (count-one-child child-r)))
          (#t
           (+ 1 (count-one-child child-l)))))
)

;problem 5

(define (insert x T)
  (cond ((null? T) (make-tree x '() '()))
        ((eq? x (value T)) T)
        ((< x (value T)) (make-tree (value T)
                                    (insert x (left T))
                                    (right T)))
        ((> x (value T)) (make-tree (value T)
                                    (left T)
                                    (insert x (right T))))))


(define (invert-bst T)
  (if (null? T) (list)
      (make-tree (value T) (invert-bst (right T)) (invert-bst (left T))))
)