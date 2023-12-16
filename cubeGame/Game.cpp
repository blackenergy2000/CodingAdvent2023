#include "cubeGame/Game.h"
#include <fstream>
#include <algio

namespace cubeGame {

Game::Game(const std::string gameDescription) {
    //find the point where the Game-ID is finished
        auto indexToCut = gameDescription.find(":") + 1;
        if(indexToCut == std::string::npos)
            std::terminate;
        //Create the strings that can be used for the subsets
        std::string allSubsets { gameDescription.substr(indexToCut) };
        std::vector<std::string> subsetList {};
        std::string localSnipet {};
        while(std::getline(allSubsets, localSnipet, ';'))
        {
            subsetList.push_back(localSnipet);
        }

        std::vector<SubGame> listOfSubgames {};
        for(auto drawInfo : subsetList) {
            listOfSubgames.emplace_back(drawInfo);
        }
        this->getMaximumForColorCubes(listOfSubgames);
}

Game::Game(size_t red, size_t green, size_t blue) : maximumAmountOfColors { {red,green,blue} } {}

const std::array<size_t,3>& Game::getMaximumForColorCubes(std::vector<SubGame>& refToSubgamesList) {
    std::array<size_t, 3> maximumValuesOfGame {0,0,0};
    for(size_t i = 0; i < (refToSubgamesList.size()-1); i++) {
        std::transform (refToSubgamesList.at(i).getColorsOfSubGame().begin(),
                        refToSubgamesList.at(i).getColorsOfSubGame().end(), refToSubgamesList.at(i + 1).getColorsOfSubGame().begin(),
                        std::back_inserter(maximumValuesOfGame), [](int a, int b) {return std::max(a,b);});  
    } 
    this->maximumAmountOfColors = maximumValuesOfGame;
    return this->maximumAmountOfColors;
}

const std::array<size_t, 3>& Game::SubGame::getColorsOfSubGame() {
    return this->amountForTheColors;
}

void Game::SubGame::getColors(const std::string& drawInfo) {
    //get the snippets of the single pull
    std::string segment { };
    std::vector<std::string> pullResult { };
    while(std::getline(drawInfo, segment, ',')) {
        pullResult.push_back(segment);
    }
    decodeSnippets(pullResult);
}

void Game::SubGame::decodeSnippets(std::vector<std::string>& pullResult) {
    for(auto snippet : pullResult) {
        for(size_t i = 0; i < this->colorStrings.size(); i++) {
            if (snippet.find(this->colorStrings.at(i)) != std::string::npos) {
                this->amountForTheColors.at(i) = std::stoul(snippet);
                break;
            }
        }
    }
}

} /*  namespace cubeGame*/