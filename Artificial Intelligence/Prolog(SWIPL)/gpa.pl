gpa(ashik, 3.45).
gpa(ashraful, 4.00).
gpa(naeem, 3.75).
gpa(biplob, 3.50).
gpa(hamidul, 3.25).
gpa(fahad, 3.00).

result :-
	write('Enter the student name: '),
	read(X),
	gpa(X, Y),
	nl,
	write('GPA is: '),
	write(Y).
