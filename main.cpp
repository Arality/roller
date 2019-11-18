#include <iostream>
#include <random>
#include <regex>

void roll(int numberDice, int diceSides);
void parseString(char *argument);

int main(int argc, char *argv[]){
//TODO Add some basic error checking
    for(int index = 1; index < argc; index++)
         parseString(argv[index]);
    return 0;
}

//Parses input then calls roll() on the arguments
void parseString(char *argument){
    std::cmatch searchResults;

    //Match any numbers at the begging of the line
    std::regex firstNumberSearchString("^\\d+");

    //Match any numbers at the end of line
    std::regex secondNumberSearchString("\\d+$");

    //Perform first search
    regex_search(argument, searchResults, firstNumberSearchString);
    int firstNumber = stoi(searchResults[0]);

    //Perform second search
    regex_search(argument, searchResults, secondNumberSearchString);
    int secondNumber = stoi(searchResults[0]);

    roll(firstNumber, secondNumber);
}

void roll(int numberDice = 0, int diceSides = 0){
    //Setup random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, diceSides);
    
    int sum {0};
    int result;
    
    for(int index = 0; index < numberDice; index++){
        result = dis(gen);
        sum = sum + result;
        std::cout << index + 1 << " roll is: " << result <<std::endl;
    }
    
    std::cout << "Results: " << sum << std::endl;
}