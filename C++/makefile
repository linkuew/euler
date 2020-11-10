targets=prob12 prob13 prob15
flags=-g -Wall

all: $(targets)

prob12:
	g++ $(flags) prob12.cpp -o twel

prob13:
	g++ $(flags) prob13.cpp -lgmp -lgmpxx -o thirteen

prob15:
	g++ $(flags) prob15.cpp -o fif

clean:
	rm twel thirteen fif
