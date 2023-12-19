#include <iostream>
#include <fstream>
#include <vector>
#include "../stringDecoding/FileNumber.h"
#include "../stringDecoding/FileSymbol.h"
#include "../stringDecoding/LineDecoder.h"

int main() { 
  auto nameOfFile {"../day3/part01/code.txt"};
  std::ifstream myFile { nameOfFile }; 
  std::string line {}; 
  if(not myFile.is_open())
      std::cout<<"File can not be opened" << std::endl;
  std::vector<FileNumber> numbers {};
  std::vector<FileSymbol> symbols {};
  size_t lineCounter { 0 };
  while(std::getline(myFile, line)) { 
      LineDecoder decoder { line, lineCounter, numbers, symbols};
      lineCounter++;
  }

  for (auto FileNumber : numbers) {
    std::cout << "FileNumber:" << std::endl;
    std::cout << "Value: " << FileNumber.value <<
      "Row: " << FileNumber.row <<
      "Col-Start: " << FileNumber.columnArea.first << 
      "Col-Stop: " << FileNumber.columnArea.second  << std::endl;
  }

  for( auto FileSymbol : symbols ) {
    std::cout << "FileSymbol:" << std::endl;
    std::cout << "Row: " << FileSymbol.position.first << "Column: " << FileSymbol.position.second << std::endl;
  }
}
