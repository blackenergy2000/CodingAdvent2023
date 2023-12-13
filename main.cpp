#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <functional>
#include <stdint.h>

struct FloorCounter {
  int32_t floorCount { 0 };

  bool basementReached { false };

  uint32_t readSigns{ 0 };

   const std::function<void(const char&)> calculate = [this](const char& sign) {
      this->readSigns++;
      if(sign == '(')
        this->floorCount++;
      else if(sign == ')')
        this->floorCount--;
      if(floorCount <= -1 and not(basementReached)) {
        basementReached = true;
        std::cout << "Im Erdgeschoss angekommen bei !" << readSigns;
      } 
    };     
};

int main() {

  FloorCounter myCounter { };

  std::ifstream myfile {"../code.txt"};
  std::string line;
  
  if (myfile.is_open()) {
    std::getline(myfile, line);
    myfile.close();  // Close the file explicitly
    std::for_each(line.begin(), line.end(), [&](const char& sign) {
      myCounter.calculate(sign);
    });
  }
  else {
    std::cerr << "Datei konnte nicht geoeffnet werden !" << std::endl;
  }
  return 0;
}
