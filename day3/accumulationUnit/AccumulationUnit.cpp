#include "AccumulationUnit.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include "../stringDecoding/FileSymbol.h"
#include "../stringDecoding/FileNumber.h"

AccumulaionUnit::AccumulationUnit(const std::vector<const FileNumber>& numbers, 
                                  const std::vector<const FileSymbol>& symbols) {
    size_t sum { 0 };
    /*
     * The algorithm itterates over the numbers and checks if the symbols of the rows
     * above and below are adjacent to the numbers
     */
    size_t currentRow { 0 };
    size_t rowNumber  { 0 };
    std::for_each(numbers.begin(), numbers.end(), [&symbols] (const FileSymbol& number) {
       size_t lowerRowLimit = number.position.first - 1;
       size_t upperRowLimit = number.position.first + 1;
       size_t lowerColumnLimit = number.position.second - 1;
       size_t upperColumnLimit = number.position.second + 1;
       for(auto symbol : symbols) {
            if(symbol.position.first >= )
       }

    });


    std::cout << "Sum of numbers that are adjecative to symbols: " << sum << std::endl;
}