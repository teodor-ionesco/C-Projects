#include "bind.h"

int main()
{
    LIB::String something = "Some dummy string to test.";
    
    LIB::String::replace("dummy", "__", something);
    
    //std::cout << something;
    
    int i; std::cin >> i;
    
    return 0;    
}
