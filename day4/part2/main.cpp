#include <iostream>
#include "../card/Card.h"
#include "../fileReader/FileReader.h"
#include "calculationUnit/CalculationUnit.h"

int main() {
    std::vector<Card> allCards { };
    //Read the data
    FileReader fileDecoder {"../day4/part2/data.txt", allCards};
    CalculationUnit calcUnit {allCards};
    return 0;
}