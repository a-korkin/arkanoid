build:
	gcc -Wall ./src/*.c -lSDL2 -lm -o game
run:
	./game
clear:
	rm ./game

