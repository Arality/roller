#include <iostream>
#include "dice.h"

Dice::Dice(){
    sum = 0;
    std::random_device rd;
    std::mt19937 gen(rd());
}

Dice::~Dice(){}

void Dice::displayResults(){
    std::cout << "Results of "<< results.size() << "d" << diceSides << " rolls:";
    for(auto &i : results){
        std::cout << i << ":";
        sum += i;
    }
    std::cout << std::endl << "The total of all rolls: " << sum << std::endl;

    //After displaying results we can discard
    sum = 0;
    results.clear();
}

void Dice::roll(int numberDice = 1, int diceSides = 1){
    std::uniform_int_distribution<> dis(1, diceSides);

    this->diceSides = diceSides;

    for(int i = 0; i < numberDice; i++)
        results.push_back(dis(gen));
    displayResults();
}
