#ifndef __CARD_H__
#define __CARD_H__

#include <vector> 
#include <cstdlib>


/*****************************************************************************************
 * @class Card
 * @brief Objects of this class represent a card game with its "correct" card and the 
 * card of the player who is playing this game.
*****************************************************************************************/
class Card {

private:
    /*****************************************************************************************
     * @brief Vector that holds the "correct" numbers of the game. 
    *****************************************************************************************/
    std::vector<size_t> correctNumbers { };

    /*****************************************************************************************
     * @brief Vector that hold the cards of the player, who plays this game.  
    *****************************************************************************************/
    std::vector<size_t> ownNumbers { };

    /*****************************************************************************************
     * @brief Vector that holds the intersected numbers between the "correct" cards and the 
     * cards of the player. 
     * 
     * @note This vector is automatically filled on construction of the card-game-object. 
    *****************************************************************************************/
    std::vector<size_t> intersectedNumbers { };

    /*****************************************************************************************
     * @brief Multiplier that shows how many copies of this elements have to be used.
     * 
     * @note This attribute is only used in part2 of the day.
    *****************************************************************************************/
    size_t multiplier { 1 };

public: 

    Card( std::vector<size_t> correctNumbers, 
          std::vector<size_t> ownNumbers ); 
    void findIntersectedNumbers();
    const std::vector<size_t>& getIntersectedNumbers() const;
    void incrementMultiplierTimes(size_t increments);
    size_t getMultiplier();

};
#endif // __CARD_H__