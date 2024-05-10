build:
	g++ -Wall ./src/*.cpp -o game.exe -lmingw32 -lSDL2 -lSD2main

run:
	./game.exe