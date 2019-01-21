all: differenzenformeln


differenzenformeln: differenzenformeln.c
	gcc -Wall -O1 --std=c99 -D_USE_MATH_DEFINES -lm -o differenzenformeln differenzenformeln.c

clean:
	rm differenzenformeln
