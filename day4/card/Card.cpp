#include "Card.h"
#include <algorithm>
#include <iostream>

/*****************************************************************************************
 * @brief Construct a new Card::Card object
 * 
 * On creation of the card-object the intersection between my cards and the cards of the 
 * game are already found. This creates the opportunity that the intersected numbers can
 * be directly accessed after the construction of the card-object. 
 * 
 * @param correctNumbers Vector that contains the "correct" numbers of the card game. 
 * @param ownNumbers Vector that contains all of "my" cards of the game. 
*****************************************************************************************/
Card::Card(std::vector<size_t> correctNumbers, 
           std::vector<size_t> ownNumbers ) :
           correctNumbers{correctNumbers},
           ownNumbers{ ownNumbers } { 
    this->findIntersectedNumbers();
}

/*****************************************************************************************
 * @brief With this methode the intersecting numbers of the card-game will be found and  
 * pushed into the intersectedNumbers-vector. This give the possibility to get the amount
 * of intersecting elements by just getting this->intersectedNumbers.size().
*****************************************************************************************/
void Card::findIntersectedNumbers() {
    std::sort(this->correctNumbers.begin(), this->correctNumbers.end());
    std::sort(this->ownNumbers.begin(), this->ownNumbers.end());
    std::set_intersection(this->correctNumbers.begin(), this->correctNumbers.end(),
                          this->ownNumbers.begin(), this->ownNumbers.end(),
                          std::back_inserter(this->intersectedNumbers));
} 

/*****************************************************************************************
 * @brief Get the vector that holds all numbers that are intersected in the card game 
 * between the correct cards of the game and mine.  
 * 
 * @return const std::vector<size_t>& Reference to the vector that contains the 
 * intersected numbers.  
*****************************************************************************************/
const std::vector<size_t>& Card::getIntersectedNumbers() const {
    return this->intersectedNumbers;
}

/*****************************************************************************************
 * @brief Set the multipliert that has to be applied because we also have copies of this
 * card.  
 * 
 * @note This function is only needed in part 2 of day 4
 * 
 * @param increments amount that needs to be added to the multiplier. 
*****************************************************************************************/
void Card::incrementMultiplierTimes(size_t increments) {
    this->multiplier += increments;
}

/*****************************************************************************************
 * @brief Returns the multiplier of the cards that represent the amounts of copies I have
 * for this card. 
 * 
 * @note This function is only needed in part 2 of day 4. 
 * 
 * @return size_t Multiplier of the card. 
*****************************************************************************************/
size_t Card::getMultiplier() {
    return this->multiplier;
} 