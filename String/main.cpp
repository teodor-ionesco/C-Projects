/*
****************************************************
* Demo for String namespace and its functions
****************************************************
*/

#include "bind.h"

int main()
{
    String::Init str1 = "Hello! I am ... string :)";
    String::Init str2 = "Hello! I am a string class.";
    String::Init str3;
    
    std::cout << str1 << std::endl;
    std::cout << str1 + str2 << std::endl;
        str3 = str1 + str2;
    std::cout << str3 << std::endl;
        str3 = "MEME" + str2 ;
    std::cout << str3 << std::endl;
    
    std::cout << String::Replace("I am", "you are", str1) << std::endl;
    std::cout << String::Replace("I am", str2, str1) << std::endl;
    std::cout << String::Replace("I am", "test", "Hello! I am something else.") << std::endl;
    
    int x; std::cin >> x;
    
    return 0;    
}
