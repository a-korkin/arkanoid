build:
	gcc -Wall ./src/*.c -lSDL2 -o game
run:
	./game
clear:
	rm ./game

