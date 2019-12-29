# TARGET: PREREQUESITES
# 	RULE

output: main.o dice.o
	@echo "Linking program..."
	g++ -g -Wall main.o dice.o -o roller

main.o: main.cpp
	@echo "Rebuilding main.cpp..."
	g++ -c -g -Wall main.cpp

dice.o: dice.cpp
	@echo "Rebuild dice.cpp..."
	g++ -c -g -Wall dice.cpp

clean:
	@echo "Cleaing..." 
	rm *.o roller
