#include "iostream"

int main()
{
    
    auto some_var1 = 20;
    auto some_var2 = 30;
    
    const auto some_const1 = 5;
    const auto some_const2 = some_var2;
    
    auto str1= new char[some_var1][some_const1];
    auto str2 = new char[some_var2][some_const2];
    
    int x; std::cin >> x;
    
    return 0;
}
