#include "iostream"

int main()
{
    #define __COMMENT(comm) #comm
    
    std::cout << __COMMENT(Some String);
    
    int x; std::cin >> x;
    
    return 0;
}
