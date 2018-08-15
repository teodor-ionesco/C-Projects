#include "iostream"

class Test
{
    
    public:
        static const char x = 3;


        friend char* accessor(Test object);
};

char* accessor(Test object)
{
    char *p = new char;
    *p = object.x;
    return p;
}

int main()
{
  
    Test testing;
    
    int x; std::cin >> x;
    
    return 0;
}
