#include "CalculationUnit.h"
#include <algorithm>
#include <iostream>
#include <cmath>

CalculationUnit::CalculationUnit(const std::vector<Card>& cardGames) {
    size_t sum { 0 };
    std::for_each(cardGames.begin(), cardGames.end(), [&sum] (const Card& card) {
        auto intersectedVectorOfGame = card.getIntersectedNumbers();
        if(intersectedVectorOfGame.size() > 0) {
            sum += std::pow(2, intersectedVectorOfGame.size() - 1);
        }
    });
    std::cout << "The result of all card games is: " << sum << std::endl;
}