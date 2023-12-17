#ifndef __GAME_H__
#define __GAME_H__

#include <array>
#include <vector>
#include <string>
#include <algorithm>

namespace cubeGame {

/*****************************************************************************************
 * @class Game
 * @brief With this class a game can be created out of the input string. 
*****************************************************************************************/
class Game {

    class SubGame;

public: 

    explicit Game(std::string gameDescription);
    Game(size_t red, size_t green, size_t blue);
    size_t getId() const;
    void getMaximumForColorCubes(std::vector<SubGame>& refToSubgamesList);


private:

    size_t id;

    std::array<size_t, 3> maximumAmountOfColors {0,0,0};

public: 

    friend constexpr bool operator>=(const Game& l, const Game& r) {
        for(size_t i = 0; i < l.maximumAmountOfColors.size(); i++) {
            if(l.maximumAmountOfColors.at(i) < r.maximumAmountOfColors.at(i))
                return false;
        }
        return true;
    }

private:
    /*****************************************************************************************
     * @class SubGame
     * @brief This class represents a drawing order of a game.
    *****************************************************************************************/
    class SubGame {

        const std::array<std::string,3> colorStrings {
            "red",
            "green",
            "blue"
        };

    protected:

        /*****************************************************************************************
         * @brief The array that contains the amount of cubes that have been pulled of the 
         * colors. 
         * 
         * Every Index represent the amount of cubes for one color:
         * 0 =>  red
         * 1 =>  green 
         * 2 =>  blue 
        *****************************************************************************************/
        std::array< size_t,3> amountForTheColors {0,0,0};

        void getColors(const std::string& drawInfo);
        void decodeSnippets(std::vector<std::string>& pullResult);

    public:

        explicit SubGame(const std::string drawInfo) {
            this->getColors(drawInfo);
        }

        const std::array<size_t, 3>& getColorsOfSubGame();
        bool isRealistic();
    };

}; 

} /*namespace cubeGamew*/

#endif // __GAME_H__