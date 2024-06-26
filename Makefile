LDLIBS = -liostream -lstdlib -lstring -lfstream

all: clean parser runner cli

cli: src/main.cpp
	g++ src/main.cpp --std=c++20 -o build/cli build/parser.o build/runner.o

runner: src/runner.cpp
	g++ -c src/runner.cpp --std=c++20 -o build/runner.o

parser: src/parser.cpp
	g++ -c src/parser.cpp --std=c++20 -o build/parser.o

clean:
	rm build/* -f
