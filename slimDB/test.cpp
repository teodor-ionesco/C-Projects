#include "iostream"

class String
{
    private:
        static const short int MAX_SIZE = 1024;
        char string[MAX_SIZE];
        
        short int __getSize(char []);
        
    public:
        String(){}
        ~String(){}
        
        char* ret()
        {
            return this -> string;    
        }
        
        void operator=(char []);
};

short int String::__getSize(char str[])
{
    short int length = 0;
    
    for(short int i = 0; i < MAX_SIZE; i++)
    {
        if(str[i] != '\0')
        {
            length++;
        }
        else
        {
            return ++length;    
        }
    }
}

void String::operator=(char str[])
{
    short int length = this -> __getSize(str);
    
    for(short int i = 0; i < length; i++)
    {
        this -> string[i] = str[i];
    }
}

int main()
{
    String alex;
    
    alex = "I love you, my dear";
    
    std::cout << alex.ret();
    
    int tmp; std::cin >> tmp;
    
    return 0;
}
