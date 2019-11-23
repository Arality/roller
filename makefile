# TARGET: PREREQUESITES
# 	RULE

output: main.o dice.o
	g++ -g -Wall main.o dice.o -o roller

main.o: main.cpp
	g++ -c -g -Wall main.cpp

dice.o: dice.cpp
	g++ -c -g -Wall dice.cpp

clean:
	rm *.o roller
