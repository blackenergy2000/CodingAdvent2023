#include "LineDecoder.h"

LineDecoder::LineDecoder(const std::string line, size_t row,
                        std::vector<FileNumber>& numbers,
                        std::vector<FileSymbol>& symbols) {
    size_t numberLength { 0 }; 
    size_t startPosition;
    bool startOfNumber { true };
    for(size_t i = 0; i < line.size(); i++) {
        if(std::isdigit(line.at(i))) { 
            numberLength++;
            if (startOfNumber) {
                startPosition = i;
                startOfNumber = false;
            }
            if (i >= line.size()-1) {
                std::string numberString = line.substr(startPosition, numberLength);
                size_t localNumber = std::stoul(numberString);
                numbers.emplace_back(localNumber, row, std::make_pair(startPosition,i));
            }
        }
        else if (not startOfNumber){
            startOfNumber = true;
            std::string numberString = line.substr(startPosition, numberLength);
            size_t localNumber = std::stoul(numberString);
            numbers.emplace_back(localNumber, row, std::make_pair(startPosition,i-1));
            numberLength = 0;
            localNumber = 0;
        }
        if ( line.at(i) != '.' and (not std::isdigit(line.at(i)))) {
            symbols.emplace_back(row, i);
        }
    }
}