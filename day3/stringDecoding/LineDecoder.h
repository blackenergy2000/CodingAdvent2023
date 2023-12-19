#include <string>
#include <vector>
#include  <algorithm>
#include "FileNumber.h"
#include "FileSymbol.h"

/*****************************************************************************************
 * @class LineDecoder
 * @brief With the current class the lines of an input file can be decoded. On decoding, 
 * objects for the numbers and symbols are created that can further be used to combine 
 * them via a needed logic. 
*****************************************************************************************/
class LineDecoder {

public:
    //Using copy for string over reference due to small string optimization
    LineDecoder(const std::string line, const size_t row, std::vector<FileNumber>& numbers, std::vector<FileSymbol>& symbols) {
            size_t numberDecade { 0 }; 
            size_t localNumber { 0 };
            size_t startPosition;
            bool startOfNumber { true };
            for(size_t i = 0; i < line.size(); i++) {
                if(std::isdigit(line.at(i))) { 
                    localNumber += (line.at(i)-'0')*(10^numberDecade);
                    numberDecade++;
                    if (startOfNumber)
                        startPosition = i;
                    if (i >= line.size()-1) {
                        numbers.emplace_back(localNumber, row, std::make_pair(startPosition,i));
                    }
                }
                else {
                    numbers.emplace_back(localNumber, row, std::make_pair(startPosition,i-1));
                    numberDecade = 0;
                    localNumber = 0;
                    startOfNumber = false;

                    if ( line.at(i) != '.') 
                        symbols.emplace_back(row, i);
                }
            }
    }

};