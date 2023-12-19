#ifndef __FILENUMBER_H__
#define __FILENUMBER_H__

#include <array>
#include <utility>

class FileNumber { 

public:

    FileNumber(const size_t value, const size_t row, const std::pair<const size_t, const size_t> columnArea) : 
        value { value }, row { row }, columnArea { columnArea } {}
    
    /*****************************************************************************************
     * @brief Array with all the potenzial numbers that need to be recognized.
    *****************************************************************************************/
    inline static const std::array<std::string, 10> possibleNumbers {
        "0",
        "1",
        "2",
        "3",
        "4",
        "5",
        "6",
        "7",
        "8",
        "9"
    };

    /*****************************************************************************************
     * @brief Value of the FileNumber. 
    *****************************************************************************************/
    const size_t value;

    /*****************************************************************************************
     * @brief Row of the symbol.
    *****************************************************************************************/
    const size_t row;

    /*****************************************************************************************
     * @brief Column-Position-Area of the FileNumber. 
    *****************************************************************************************/
    const std::pair<const size_t, const size_t> columnArea;

};
#endif // __FILENUMBER_H__