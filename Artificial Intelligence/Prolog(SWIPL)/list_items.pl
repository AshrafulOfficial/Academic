item(tshirt).
item(shoe).
item(socks).
item(laptop).
item(tv).
item(sunglass).
item(cap).
item(pant).

product :-
	item(X),
	write(X),
	nl,
	fail.
	
product.
