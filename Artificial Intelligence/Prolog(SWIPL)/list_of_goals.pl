big(bear).
big(lion).

small(dog).
small(cat).

brown(lion).
black(dog).
gray(cat).
white(bear).

dark(Z):-
	black(Z).
dark(Z):-
	brown(Z).
dark(Z):-
	gray(Z).
	
light(Z):-
	white(Z).
