#include "FileReader.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>

FileReader::FileReader(const std::string& fileName, std::vector<Card>& cards) {
    std::ifstream myFile { fileName }; 
    std::string line {};
    if(not myFile.is_open())
        std::cout<<"File can not be opened" << std::endl;
    while(std::getline(myFile, line)) { 
        std::vector<size_t> correctNumbers { };
        std::vector<size_t> myNumbers { };
        auto firstCutPoisition = line.find(":");
        auto secondCutPosition = line.find("|");
        std::string correctNumberString =
            line.substr(firstCutPoisition + 1, secondCutPosition - (firstCutPoisition + 1));
        std::string myNumberString = 
            line.substr(secondCutPosition + 1);
        this->convertLineToNumbers(correctNumberString, correctNumbers);
        this->convertLineToNumbers(myNumberString, myNumbers);
        cards.emplace_back(correctNumbers, myNumbers);
    }
}

void FileReader::convertLineToNumbers(std::string line, std::vector<size_t>& numbers){
    std::string numberString { };
    std::istringstream lineStream { line };
    while(std::getline(lineStream, numberString, ' ')) {
        numberString.erase(std::remove(numberString.begin(), numberString.end(), ' '), numberString.end());
        if(not numberString.empty()) {
            numbers.push_back(std::stoul(numberString));
        } 
    }
}