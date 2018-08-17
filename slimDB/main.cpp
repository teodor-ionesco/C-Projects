#include "bind.h"

int main()
{
    LIB::String something = "Some dummy string to test.";
    
    
    
    std::cout << LIB::String::replace("dummy", "ordinary", "Some dummy string to test.");
    
    int i; std::cin >> i;
    
    return 0;    
}
