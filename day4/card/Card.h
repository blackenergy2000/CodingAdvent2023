#include <vector> 
#include <cstdlib>

class Card {

private:
    std::vector<size_t> correctNumbers { };

    std::vector<size_t> ownNumbers { };

public: 

    Card( const std::vector<size_t> correctNumbers, 
          const std::vector<size_t> ownNumbers ); 

};