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
  while(not myFile.eof()) { 
      std::string line {}; 
      std::getline(myFile, line);
      gamesToCheck.emplace_back(line);
  }
  //Execute the check
  size_t correctGames { 0 };
  std::for_each(gamesToCheck.begin(), gamesToCheck.end(), [&correctGames, &myGame](const cubeGame::Game& gameToCheck){
    if(myGame >= gameToCheck)
      correctGames++;
  });

  std::cout<<"The amount of legal games is: " << correctGames;
  return 0;
}
