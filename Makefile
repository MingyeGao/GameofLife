all: src test

test: test/testParseCommandLine.cc src

src: src/parseCommandLine.cc.o
	test -d src.a || touch src.a

src/parseCommandLine.cc.o :src/parseCommandLine.cc src/parseCommandLine.h
	g++ -g -std=c++11 -o obj/parseCommandLine.cc.o -c src/parseCommandLine.cc
	ar -rs src.a obj/parseCommandLine.cc.o

test: test/testParseCommandLine.cc src
	g++ -g -std=c++11 -o obj/testParseCommandLine.cc.o -c test/testParseCommandLine.cc
	g++ -o testParseCommandLine obj/parseCommandLine.cc.o obj/testParseCommandLine.cc.o