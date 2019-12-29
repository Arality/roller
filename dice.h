#pragma once
#include <random>

class Dice{
    private:
        int diceSides;
        std::vector<long long> results;
        long long sum;
        std::random_device rd;
        std::mt19937 gen;

        void displayResults();

    public:
        Dice();
        ~Dice();
        void roll(int numberDice, int diceSides);
};