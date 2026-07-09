studies(ashraful, cse321).
studies(naeem, cse321).
studies(hamidul, cse400).
studies(fahad, cse400).
studies(biplob, cse221).
studies(nazmul, cse221).

teaches(tushar_sir, cse321).
teaches(mijan_sir, cse400).
teaches(ujjal_sir, cse221).

professor(X, Y) :-
	studies(Y, Z),
	teaches(X, Z).
