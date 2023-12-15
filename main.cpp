  #include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <functional>
#include <stdint.h>

struct FloorCounter {

  std::vector<uint8_t> numbers { };

  unsigned total { 0 };

  FloorCounter() {
    this->numbers.reserve(10);
  }

  const std::function<void(const char&)> saveSign = [this](const char& sign) {
      if( isdigit(sign) ) {
        this->numbers.push_back(static_cast<uint8_t>(sign)-48);
      }
  };     
};

int main() {

  FloorCounter myCounter { };

  std::ifstream myfile {"../code.txt"};
  std::string line;     
  
  if (myfile.is_open()) {
    while(not myfile.eof()) { 
      std::getline(myfile, line);
        std::for_each(line.begin(), line.end(), [&](const char& sign) {
        myCounter.saveSign(sign);
      });
      //Build the sum of the single digits
      uint8_t digit { 0 };
      switch(  myCounter.numbers.size() ) { 
        case 0:
          break;
        case 1:
          digit = myCounter.numbers.at(0);
          myCounter.total += static_cast<unsigned>(digit*10 + digit);
          break;
        default:
          if( myCounter.numbers.size() >= 2) { 
            myCounter.total += static_cast<unsigned>(myCounter.numbers.front() * 10 + myCounter.numbers.back());
          }
          break;
      }
      //The datafield needs to be cleared for the usage together with the next line s
      myCounter.numbers.clear();
    }
    std::cout << "The sum of the decrypter numbers is: " << myCounter.total;
     
  }
  else {
    std::cerr << "File could not be opened!" << std::endl;
  }
  return 0;
}
