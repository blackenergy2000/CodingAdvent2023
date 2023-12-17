#include <iostream>
#include <fstream>
#include "cubeGame/Game.h"

int main(){
  //Game to which the comparison has to be made
  cubeGame::Game myGame {12,13,14};
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
  size_t correctGames { 0 };
  std::for_each(gamesToCheck.begin(), gamesToCheck.end(), [&correctGames, &myGame](const cubeGame::Game& gameToCheck){
    if(myGame >= gameToCheck)
      correctGames += gameToCheck.getId();
  });

  std::cout<<"The amount of legal games is: " << correctGames;
  return 0;
}
