FLAGS = -Werror -std=c++20

all : clean classes

classes:
	clang++ ${FLAGS} main.cpp Tile/Tile.cpp Board/Board.cpp Direction/Direction.cpp Point/Point.cpp -o main

clean:
	rm -rf main

