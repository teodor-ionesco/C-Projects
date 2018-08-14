#include "iostream"

class Test
{
    static char string[120];
    
    public:
        friend char* accessor(Test object);
};

char* accessor(Test object)
{
    return object.string;
}

int main()
{
    Test testing;
    
    

    int x; std::cin >> x;
    
    return 0;
}
