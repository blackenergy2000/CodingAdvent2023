#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

int main() {
  std::ifstream myfile {"../code.txt"};
  std::string line;
  
  if (myfile.is_open()) {
    std::getline(myfile, line);
    myfile.close();  // Close the file explicitly
    size_t amountOfOpeningBrackets =  std::count(line.begin(), line.end(), '(');
    size_t amountOfClosingBrackets = std::count(line.begin(), line.end(), ')');
    std::cout << "Anzahl an Bracket-Diff: " << amountOfOpeningBrackets-amountOfClosingBrackets;
  }
  else {
    std::cerr << "Datei konnte nicht geoeffnet werden !" << std::endl;
  }
  
  return 0;
}
