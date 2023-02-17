// add your code as appropriate 
#include <iostream>
#include "reservoir.h"
#include "reverseorder.h"


int main() {
    std::cout << "East basin storage: " << 
get_east_storage("12/20/2018") << " billion galls" << "\n"; 
    std::cout << "Minimum storage in East basin: " << 
get_min_east() << " billion gallons" << "\n"; 
    std::cout << "Minimum storage in East basin: " << 
get_max_east() << " billion gallons" << "\n"; 
    std::cout << compare_basins("01/08/2018") << "\n"; 
    reverse_order("01/02/2018", "01/05/2018"); 
}
  

  
