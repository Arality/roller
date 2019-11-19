# TARGET: PREREQUESITES
# 	RULE

output: main.o
	g++ -g -Wall main.o -o roller

main.o: main.cpp
	g++ -c -Wall main.cpp

clean:
	rm *.o roller
