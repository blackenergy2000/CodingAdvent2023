#include "AccumulationUnit.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include "../stringDecoding/FileSymbol.h"
#include "../stringDecoding/FileNumber.h"

AccumulationUnit::AccumulationUnit(const std::vector<FileNumber>& numbers, 
                                  const std::vector<FileSymbol>& symbols) {
    size_t sum { 0 };
    /*
     * The algorithm itterates over the numbers and checks if the symbols of the rows
     * above and below are adjacent to the numbers
     */
    size_t currentRow { 0 };
    size_t rowNumber  { 0 };
    std::for_each(numbers.begin(), numbers.end(), [&symbols, &sum] (const FileNumber& number) {
       size_t lowerRowLimit = (number.row == 0) ? 0 : number.row-1;
       size_t upperRowLimit = number.row + 1;
       size_t lowerColumnLimit = (number.columnArea.first == 0) ? 0 : number.columnArea.first-1;
       size_t upperColumnLimit = number.columnArea.second + 1;
       for(auto symbol : symbols) {
         auto symbolRow = symbol.position.first;
         auto columnRow = symbol.position.second;
            if(symbolRow >= lowerRowLimit and
               symbolRow <= upperRowLimit and 
               columnRow >= lowerColumnLimit and
               columnRow <= upperColumnLimit) {
                  sum += number.value;
                  break;
               }
       }
    });
    std::cout << "Sum of numbers that are adjecative to symbols: " << sum << std::endl;
}