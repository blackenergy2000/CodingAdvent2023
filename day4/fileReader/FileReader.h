#ifndef __FILEREADER_H__
#define __FILEREADER_H__

#include <string>
#include "../card/Card.h"

/*****************************************************************************************
 * @class FileReader
 * @brief This class can be used to format the input file into small packages that can
 * then be further processed.
*****************************************************************************************/
class FileReader {

public:
    FileReader(const std::string& fileString, std::vector<Card>& cards);
private:   
    void convertLineToNumbers(std::string line, std::vector<size_t>& numbers);
};
#endif // __FILEREADER_H__