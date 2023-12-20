#include <vector>
#include "../stringDecoding/FileNumber.h"
#include "../stringDecoding/FileSymbol.h"

/*****************************************************************************************
* @class AccumulationUnit
* @brief Class that find the numbers that are legal in the context of the assignment.
* (Numbers that have a distance of 1 to symbols)
*****************************************************************************************/
class AccumulationUnit {
public:
    AccumulationUnit(const std::vector<FileNumber>& numbers, 
                     const std::vector<FileSymbol>& symbols);

};