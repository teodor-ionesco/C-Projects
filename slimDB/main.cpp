#include "h/bind.h"


int main()
{
    //LIB::String something = LIB::String::replace("i", "", "Hi, I love you");
    
    //something = LIB::String::replace("~+", "ordinary", "Hi ~+ and ^*. Is ^* still flying around ~+?");
    
    std::cout << LIB::String::replace("ii", "XXXX", "Hiiiii, my name is rabbit!");
    
    //short int list[] = {24, 15, 99, 54, 5};
    
   // char clist[] = "24, 15, 99, 54, 5";

    //LIB::Sort::asc(clist);
    
    //std::cout << something;
        
    int i; std::cin >> i;
    
    return 0;    
}
