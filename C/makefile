# Just a temp makefile, will have to update it to be more streamlined
# in the future
CO=gcc -g -Wall
elem=prob1 prob2 prob3 prob4 prob5 prob19 prob22

all: $(elem)

prob1:
	$(CO) prob1.c -o one

prob2:
	$(CO) prob2.c -o two

prob3:
	$(CO) prob3.c -o three

prob4:
	$(CO) prob4.c -o four -lm

prob5:
	$(CO) prob5.c -o five

prob19:
	$(CO) prob19.c -o nineteen

prob22:
	$(CO) prob22.c -o twentytwo

clean:
	rm one two three four five nineteen twentytwo
