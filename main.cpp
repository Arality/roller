#include <iostream>
#include <regex>

#include "dice.h"

static void extractNumbers(const std::string &stringToSeach, Dice &obj);

int main(const int argc, const char *argv[]){
//TODO Add some basic error checking, with unit testing
    Dice roller;

    if(argc <= 1){
        std::cout << "You haven't entered any arguments" << std::endl;
        std::cout << "The correct usage is: <number of dice>d<sides on dice>" << std::endl;
        return -1;
    }

    for(int i = 1; i < argc; i++){
        extractNumbers(argv[i], roller);
    }
    return 0;
}

//Removes numbers at beginning and end of string then calls passed function with the arguments
static void extractNumbers(const std::string &stringToSeach, Dice &obj){
    int firstNumber {0};
    int secondNumber {0};
    std::smatch searchResults;

    //Match any numbers at the begging of the line
    std::regex firstNumberSearchString("^\\d+");

    //Match any numbers at the end of line
    std::regex secondNumberSearchString("\\d+$");

    //Perform first search
    regex_search(stringToSeach, searchResults, firstNumberSearchString);

    //Extract results and store in firstNumber
    try{
        firstNumber = stoi(searchResults[0]);
    }
    //TODO expand specific catch conditions, with unit testing
    catch(std::out_of_range){
        std::cout << "Your first number was out of range" << std::endl;
    }
    catch(...){ 
        std::cout << "Sorry there was an error with the number of dice" << std::endl;
    }

    //Perform second search
    regex_search(stringToSeach, searchResults, secondNumberSearchString);

    //Extract results and store in secondNumber
    try{
        secondNumber = stoi(searchResults[0]);
    }
    //TODO expand specific catch conditions, with unit testing
    catch(std::out_of_range){
        std::cout << "Your second number was out of range" << std::endl;
    }
    catch(...){
        std::cout << "Sorry there was an error with the number of sides" << std::endl;
    }

    obj.roll(firstNumber, secondNumber);
}