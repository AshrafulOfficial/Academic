gcd(X, 0, X).

gcd(X, Y, G):-
	Y>0,
	R is X mod Y,
	gcd(Y, R, G).
	
lcm(X, Y, L):-
	gcd(X, Y, G),
	L is (X*Y)/G.
