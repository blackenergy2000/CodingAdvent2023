  #include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <functional>
#include <stdint.h> 
#include <array>
#include <optional>


struct FloorCounter { 

  /*****************************************************************************************
   * @brief Arrays that are used to store the minimal and maximal position at which the 
   * numbers of the string are located. 
  *****************************************************************************************/
  std::array<size_t, 10> lowerPosition { };
  std::array<size_t, 10> upperPosition { };  


  FloorCounter() { }  
};

  /*****************************************************************************************
   * @brief Array with all the strings that can be interpreted as numbers. 
  *****************************************************************************************/
  static const std::array<std::string_view, 10> charNumbers {
    "zero",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine"
  }; 

 /*****************************************************************************************
   * @brief Array with all the numbers. 
  *****************************************************************************************/
  static const std::array<std::string, 10> numbers {
    "0",
    "1",
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
    "9"
  };

int main() {
  size_t totalValue { 0 };
  std::ifstream myfile {"../code.txt"};
  std::string line;     
  
  if (myfile.is_open()) {
    while(not myfile.eof()) { 
      std::getline(myfile, line);
      FloorCounter myCounter { };
      bool firstValueFound { false };
      bool secondValueFound { false };
      uint8_t lowerValue, higherValue { 0 };
      
      size_t lengthOfSubstring { 1 };
      while(lengthOfSubstring <= line.size() and (not firstValueFound)) {
        std::string testSequence { line.substr( 0,lengthOfSubstring) };
        for(size_t i = 0; i < numbers.size(); i++) {
          if(( testSequence.find(charNumbers.at(i)) != std::string::npos) or 
            (testSequence.find(numbers.at(i)) != std::string::npos)) {
            std::cout<<"Erster String: " << testSequence << std::endl;
            firstValueFound = true;
            lowerValue = i;
            break;
          }
        }
        lengthOfSubstring++;
      }

      lengthOfSubstring = 1;
      while (lengthOfSubstring <= line.size() and firstValueFound and (not secondValueFound)) {
        std::string testSequence { line.substr(line.size()-lengthOfSubstring) };
        for(size_t i = 0; i < charNumbers.size(); i++) {
          if((testSequence.find(charNumbers.at(i)) != std::string::npos) or
           (testSequence.find(numbers.at(i)) != std::string::npos)) {
            std::cout<<"Zweiter String: " << testSequence << std::endl;
            secondValueFound = true;
            higherValue = i;
            break;
          }
        }
        lengthOfSubstring++;
      }
      size_t valueToAdd { 0 };
      if(firstValueFound and not secondValueFound) {
        valueToAdd += lowerValue * 10 + lowerValue;
      }
      else if (firstValueFound and secondValueFound) {
        valueToAdd += lowerValue * 10 + higherValue;
      }
      totalValue += valueToAdd;
      std::cout<<"Zwischenwert:"<<valueToAdd<<std::endl;
    }
  }
  std::cout << "The sum of the decrypter numbers is: " << totalValue;
  return 0;
}
