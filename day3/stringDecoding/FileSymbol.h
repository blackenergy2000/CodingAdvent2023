#ifndef __FILESYMBOL_H__
#define __FILESYMBOL_H__

#include <cstdint>
#include <utility>
#include <string>

class FileSymbol {

public:

FileSymbol(const size_t row, const size_t column) : position{std::make_pair(row, column)} { }

/*****************************************************************************************
 * @brief Position of the FileSymbol inside the text file. 
 * 
 * @note 
 * The first value represents the row of the FileSymbol.
 * The second value represents the column of the FileSymbol. 
*****************************************************************************************/
const std::pair<const size_t, const size_t> position;

};
#endif // __FILESYMBOL_H__