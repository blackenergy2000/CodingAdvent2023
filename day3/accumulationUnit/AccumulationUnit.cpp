#include "AccumulationUnit.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include "../stringDecoding/FileSymbol.h"
#include "../stringDecoding/FileNumber.h"

AccumulationUnit::AccumulationUnit(const std::vector<FileNumber>& numbers, 
                                  const std::vector<FileSymbol>& symbols) {
    size_t sum { 0 };
    /**
     * The algorithm in this version iterates over the symbols of the text file and counts the amount
     * of numbers that are adjacent to the symbols.
     */
   size_t currentRow { 0 };
   size_t rowNumber  { 0 };
   std::for_each(symbols.begin(), symbols.end(), [&numbers, &sum](const FileSymbol& symbol) {
      std::vector<size_t> adjacentNumbers { };
      for(auto number : numbers) {
         //Calculate the distance between the rows 
         auto verticalDistance {std::abs(static_cast<int>(symbol.position.first-number.row))};
         auto horizontalDistance {
            std::min(
               std::abs(static_cast<int>(symbol.position.second - number.columnArea.first)),
               std::abs(static_cast<int>(symbol.position.second - number.columnArea.second))
            )
         };
         if(verticalDistance <= 1 and horizontalDistance <= 1) {
            adjacentNumbers.push_back(number.value);
         }
      }
      if(adjacentNumbers.size() >= 2) {
         sum += (adjacentNumbers.at(0) * adjacentNumbers.at(1));
      }
   });
   std::cout << "Sum of numbers that are adjecative to symbols: " << sum << std::endl;
}