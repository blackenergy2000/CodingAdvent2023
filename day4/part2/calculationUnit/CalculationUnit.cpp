#include "CalculationUnit.h"
#include <algorithm>
#include <iostream>

CalculationUnit::CalculationUnit(std::vector<Card>& cardGames) {
    size_t sum { 0 };
    for(auto i = 0; i < cardGames.size(); i++) {
       auto intersectedVectorOfGame = cardGames.at(i).getIntersectedNumbers();
       if (intersectedVectorOfGame.size() > 0) {
            size_t resultOfCardAndCopies = intersectedVectorOfGame.size();
            for(size_t j = 1; j <= resultOfCardAndCopies; j++) {
                if((i+j) < cardGames.size()) {
                    cardGames.at(i+j).incrementMultiplierTimes(cardGames.at(i).getMultiplier());
                }
            }
       }   
       sum += cardGames.at(i).getMultiplier();  
    }
    std::cout << "The result of all card games is: " << sum << std::endl;
}