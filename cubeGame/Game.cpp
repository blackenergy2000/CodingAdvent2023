#include <fstream>
#include <sstream>
#include <algorithm>
#include <iostream>
#include "Game.h"

namespace cubeGame {

Game::Game(const std::string gameDescription) {
    //find the point where the Game-ID is finished
    auto indexToCut = gameDescription.find(":") + 1;
    if(indexToCut == std::string::npos)
        std::terminate;
    //Create the string that can be used for the id 
    std::string gameString { gameDescription.substr(0, indexToCut-1) };
    std::string idAsString { gameString.substr(gameString.find(" "))};
    this->id = std::stoul(idAsString);
    //Create the strings that can be used for the subsets
    std::istringstream allSubsets { gameDescription.substr(indexToCut) };
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

Game::Game(size_t red, size_t green, size_t blue) : maximumAmountOfColors{ {red,green,blue} } {}

void Game::getMaximumForColorCubes(std::vector<SubGame>& refToSubgamesList) {
    for(auto gameToCompare : refToSubgamesList) {
        size_t i { 0 }; 
        for(auto colorValue : gameToCompare.getColorsOfSubGame()) {
            if(this->maximumAmountOfColors.at(i) < colorValue)
                this->maximumAmountOfColors.at(i)= colorValue;
            i++;
        }
    }
}

size_t Game::getId() const{
    return this->id;
}
    
const std::array<size_t, 3>& Game::getColorAmountsForLegalGame() const {
    return this->maximumAmountOfColors;
};


const std::array<size_t, 3>& Game::SubGame::getColorsOfSubGame() {
    return this->amountForTheColors;
}

void Game::SubGame::getColors(const std::string& drawInfo) {
    std::istringstream infoStream { drawInfo };
    //get the snippets of the single pull
    std::string segment { };
    std::vector<std::string> pullResult { };
    while(std::getline(infoStream, segment, ',')) {
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