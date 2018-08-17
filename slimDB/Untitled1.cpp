#include "iostream"

short int len(const char* str)
{
    short int length = 0;
    
    for(short int i = 0; i >= 0; i++)
    {
        if(str[i] != '\0')
            ++length;
        else
            break;
    }
    
    return ++length;
}

void concat(char* str1, char str2[])
{
    int str1_len = len(str1);
    int str2_len = len(str2);
    
    //char *tmp = new char[(str1_len+str2_len)-1];
    
    for(int i = 0; i < str2_len; i++)
        str1[i+(str1_len-1)] = str2[i];
}

int main()
{
    char str1[] = "ss ";
    char str2[] = "worldz";
    
    concat(str1, str2);
    
    std::cout << str1;
    
    int x; std::cin >> x;
    
    return 0;
}
