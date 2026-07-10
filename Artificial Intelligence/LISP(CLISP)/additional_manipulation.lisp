(setq mylist '(1 2 3 4 5))

(print (reverse mylist))
(print (member 3 mylist))
(print (nth 2 mylist))
(print (length mylist))
(print (mapcar #'(lambda (x) (* x x)) mylist))
