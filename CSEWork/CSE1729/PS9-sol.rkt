;(define (huffman freqs)
 ; (define (htree-leaf letter weight) (list 'leaf weight letter))
  ;(define (htree-node t0 t1) (list 'internal (+ (htree-weight t0) (htree-weight t1)) t0 t1))
  ;(define (htree-weight t) (cadr t))
;  ...
;)

;problem 1

(define (get-count text)
  (define word (string->list text))
  (define (help lst count)
    (if (null? lst) count
        (if (null? count)
            (append count (cons (car lst) 1))
            (if (eq? letter (car (car count2)))
                (cons (car (car count2)) (+ (cdr (car count2)) 1))
                (append (car count) (help (cdr lst) count)))))
  )
  (reverse (help word '()))
)


;problem 2

(define (count lst)
  (if (null? lst) 0
      (+ (cdr (car lst)) (count (cdr lst))))
)

(define (get-freq l)
  (define total (count l))
  (define (help lst)
    (if (null? lst) '()
        (append (cons (car (car lst)) (/ (cdr (car lst)) total)) (help (cdr lst))))
  )
  (help (get-count text))
)
