all: POWER

POWER:
	gcc -Wall -ansi -Iinclude src/powers.c src/powersF.c -o bin/powers

clean:
	rm -rf *o bin/powers
