#include <string>
#include <vector>
#include <algorithm>
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
    LineDecoder(const std::string line,
                const size_t row,
                std::vector<FileNumber>& numbers,
                std::vector<FileSymbol>& symbols);
};