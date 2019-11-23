#include <iostream>
#include <random>
#include <regex>
#include <vector>
#include <string>

class Dice{
    private:
        int diceSides;
        int numberDice;
        std::vector<long long> results;
        long long sum;

        void displayResults();

    public:
        Dice();
        ~Dice();
        void roll(int numberDice, int diceSides);
};