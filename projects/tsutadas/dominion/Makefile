CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

betterTestDrawCard: betterTestDrawCard.c dominion.o rngs.o
	gcc -o betterTestDrawCard -g  betterTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

unittest1: unittest1.c dominion.o rngs.o
	gcc -o unittest1 -g  unittest1.c dominion.o rngs.o $(CFLAGS)

unittest2: unittest2.c dominion.o rngs.o
	gcc -o unittest2 -g  unittest2.c dominion.o rngs.o $(CFLAGS)

unittest3: unittest3.c dominion.o rngs.o
	gcc -o unittest3 -g  unittest3.c dominion.o rngs.o $(CFLAGS)

unittest4: unittest4.c dominion.o rngs.o
	gcc -o unittest4 -g  unittest4.c dominion.o rngs.o $(CFLAGS)

cardtest1: cardtest1.c dominion.o rngs.o
	gcc -o cardtest1 -g cardtest1.c dominion.o rngs.o $(CFLAGS)

cardtest2: cardtest2.c dominion.o rngs.o
	gcc -o cardtest2 -g cardtest2.c dominion.o rngs.o $(CFLAGS)

cardtest3: cardtest3.c dominion.o rngs.o
	gcc -o cardtest3 -g cardtest3.c dominion.o rngs.o $(CFLAGS)

cardtest4: cardtest4.c dominion.o rngs.o
	gcc -o cardtest4 -g cardtest4.c dominion.o rngs.o $(CFLAGS)

randomtestadventurer: randomtestadventurer.c dominion.o rngs.o
	gcc -o randomtestadventurer -g randomtestadventurer.c dominion.o rngs.o $(CFLAGS)

randomtestcard1: randomtestcard1.c dominion.o rngs.o
	gcc -o randomtestcard1 -g randomtestcard1.c dominion.o rngs.o $(CFLAGS)

randomtestcard1.out: randomtestcard1.c dominion.o rngs.o
	echo "Rssult for runninng randomtestcard1:" >> randomtestcard1.out
	
	gcc -o randomtestcard1 -g randomtestcard1.c dominion.o rngs.o $(CFLAGS)
	./randomtestcard1 >> randomtestcard1.out
	# ./randomtestadventurer
	gcov dominion.c -b >> randomtestcard1.out
	# ./randomtestadventurer

randomtestcard2: randomtestcard2.c dominion.o rngs.o
	gcc -o randomtestcard2-g randomtestcard2.c dominion.o rngs.o $(CFLAGS)

randomtestcard2.out: randomtestcard2.c dominion.o rngs.o
	echo "Rssult for runninng randomtestcard2:" >> randomtestcard2.out
	
	gcc -o randomtestcard2 -g randomtestcard2.c dominion.o rngs.o $(CFLAGS)
	./randomtestcard2 >> randomtestcard2.out
	# ./randomtestadventurer
	gcov dominion.c -b >> randomtestcard2.out
	# ./randomtestadventurer

randomtestadventurer.out: randomtestadventurer.c dominion.o rngs.o
	echo "Rssult for runninng randomtestadventurer:" >> randomtestadventurer.out
	
	gcc -o randomtestadventurer -g randomtestadventurer.c dominion.o rngs.o $(CFLAGS)
	./randomtestadventurer >> randomtestadventurer.out
	# ./randomtestadventurer
	gcov dominion.c -b >> randomtestadventurer.out
	# ./randomtestadventurer


unittestresults.out: unittest1.c unittest2.c unittest3.c unittest4.c cardtest1.c cardtest2.c cardtest3.c cardtest4.c  dominion.o rngs.o
	echo "Rssult for runninng unittests:" > unittestresults.out

	echo "unittest1.c:" >> unittestresults.out
	gcc -o unittest1 -g  unittest1.c dominion.o rngs.o $(CFLAGS)
	./unittest1 >> unittestresults.out
	gcov dominion.c -b >> unittestresults.out

	echo "unittest2.c:" >> unittestresults.out
	gcc -o unittest2 -g  unittest2.c dominion.o rngs.o $(CFLAGS)
	./unittest2 >> unittestresults.out
	gcov dominion.c -b >> unittestresults.out

	echo "unittest3.c:" >> unittestresults.out
	gcc -o unittest3 -g  unittest3.c dominion.o rngs.o $(CFLAGS)
	./unittest3 >> unittestresults.out
	gcov dominion.c -b >> unittestresults.out

	echo "unittest4.c:" >> unittestresults.out
	gcc -o unittest4 -g  unittest4.c dominion.o rngs.o $(CFLAGS)
	./unittest4 >> unittestresults.out
	gcov dominion.c -b >> unittestresults.out

	echo "Result for runnint cardtests:" >> unittestresults.out

	echo "cardtest1.c:" >> unittestresults.out
	gcc -o cardtest1 -g cardtest1.c dominion.o rngs.o $(CFLAGS)
	./cardtest1 >> unittestresults.out
	gcov dominion.c -b >> unittestresults.out

	echo "cardtest2.c:" >> unittestresults.out
	gcc -o cardtest2 -g cardtest2.c dominion.o rngs.o $(CFLAGS)
	./cardtest2 >> unittestresults.out
	gcov dominion.c -b >> unittestresults.out

	echo "cardtest3.c:" >> unittestresults.out
	gcc -o cardtest3 -g cardtest3.c dominion.o rngs.o $(CFLAGS)
	./cardtest3 >> unittestresults.out
	gcov dominion.c -b >> unittestresults.out

	echo "cardtest4.c:" >> unittestresults.out
	gcc -o cardtest4 -g cardtest4.c dominion.o rngs.o $(CFLAGS)
	./cardtest4 >> unittestresults.out
	gcov dominion.c -b >> unittestresults.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player betterTestDrawCard testDrawCard testBuyCard badTestDrawCard unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 unittestresults.out randomtestadventurer.out randomtestcard1.out randomtestcard2.out
# all: playdom player betterTestDrawCard testDrawCard testBuyCard badTestDrawCard randomtestadventurer.out

clean:
	rm -rf *.dSYM *.o playdom.exe playdom test.exe test player player.exe testInit testDrawCard badTestDrawCard testInit.exe *.gcov *.gcda *.gcno *.so unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 unittestresults.out randomtestadventurer randomtestadventurer.out betterTestDrawCard randomtestcard1 randomtestcard1.out randomtestcard2 randomtestcard2.out
