#include <iostream>
#include <fstream>
#include "cubeGame/Game.h"

int main(){
  //File with the events that need to be checked
  auto nameOfFile {"../code.txt"};
  std::ifstream myFile { nameOfFile }; 
  std::vector<cubeGame::Game> gamesToCheck { };
  std::string line {}; 
  if(not myFile.is_open())
      std::cout<<"File can not be opened" << std::endl;
  while(std::getline(myFile, line)) { 
    cubeGame::Game localGame { line };
    gamesToCheck.emplace_back(line);
  }
  //Execute the check
  size_t totalPower { 0 };
  std::for_each(gamesToCheck.begin(), gamesToCheck.end(), [&totalPower](const cubeGame::Game& gameToCheck){
    auto powerElements = gameToCheck.getColorAmountsForLegalGame();
    size_t power { 1 };
    std::for_each(powerElements.begin(), powerElements.end(), [&power](const size_t& colorPower) {
      power *= colorPower;
    });
    totalPower += power;
  });

  std::cout<<"The amount of legal games is: " << totalPower;
  return 0;
}
