;problem 1

(define (fact n)
  (let ((total 1)
        (count 1))
    (define (help)
      (cond ((or (= n 0) (= count n)) 'done)
            (else
             (set! count (+ count 1))
             (set! total (* total count))
             (help))))
    (help)
    total)
)

;problem 2

(define (new-account initial-balance)
  (let ((balance initial-balance)
        (interest .01))
    (define (deposit f)
      (set! balance (+ balance f))
      balance)
    (define (withdraw f)
      (cond ((> f balance) (+ "Withdrawal not allowed since balance is $" (number->string balance)))
            (else
             (set! balance (- balance f))
             balance)))
    (define (accrue)
      (set! balance (* balance (+ 1 interest)))
      balance)
    (define (setrate i)
      (set! interest i))
    (define (bal-inq) balance)
    (lambda (method)
      (cond ((eq? method 'deposit) deposit)
            ((eq? method 'withdraw) withdraw)
            ((eq? method 'balance-inquire) bal-inq)
            ((eq? method 'accrue) accrue)
            ((eq? method 'setrate) setrate))))
)

