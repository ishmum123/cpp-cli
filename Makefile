LDLIBS = -liostream -lstdlib -lstring -lfstream

all: clean cli

cli: src/main.cpp
	g++ src/main.cpp --std=c++17 -o build/cli

clean:
	rm build/* -f
