all: beforeMake src test

beforeMake:
	test -d obj || mkdir obj

test: testParseCommandLine testCell testBackground testBackgroundStart

src: parseCommandLine.cc.o Cell.cc.o Background.cc.o

Cell.cc.o: src/Cell.cc src/Cell.h
	g++ -g -std=c++11 -o obj/Cell.cc.o -c src/Cell.cc
	

parseCommandLine.cc.o :src/parseCommandLine.cc src/parseCommandLine.h
	g++ -g -std=c++11 -o obj/parseCommandLine.cc.o -c src/parseCommandLine.cc
	#ar -rs src.a obj/parseCommandLine.cc.o

Background.cc.o: src/Background.h src/Background.cc
	g++ -g -std=c++11 -o obj/Background.cc.o -c src/Background.cc

testParseCommandLine: test/testParseCommandLine.cc src
	g++ -g -std=c++11 -o obj/testParseCommandLine.cc.o -c test/testParseCommandLine.cc
	g++ -o testParseCommandLine obj/parseCommandLine.cc.o obj/testParseCommandLine.cc.o
	#g++ -o testParseCommandLine src.a obj/testParseCommandLine.cc.o

testCell: test/testCell.cc src
	g++ -g -std=c++11 -o obj/testCell.cc.o -c test/testCell.cc
	g++ -o testCell obj/testCell.cc.o obj/Cell.cc.o

testBackground: src test/testBackground.cc
	g++ -g -std=c++11 -o obj/testBackground.cc.o -c test/testBackground.cc
	g++ -o testBackground obj/testBackground.cc.o obj/Background.cc.o obj/Cell.cc.o obj/parseCommandLine.cc.o

testBackgroundStart: src test/testBackgroundStart.cc
	g++ -g -std=c++11 -o obj/testBackgroundStart.cc.o -c test/testBackgroundStart.cc
	g++ -o testBackgroundStart obj/testBackgroundStart.cc.o obj/Background.cc.o obj/Cell.cc.o obj/parseCommandLine.cc.o

clean:
	-rm -rf obj/
	-rm test*