#include "iostream"

class Str_Replace{
    
    static short int len(const char* str)
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
    
    static void concat(char* str1, char str2[])
    {
        int str1_len = len(str1);
        int str2_len = len(str2);
        
        for(int i = 0; i < str2_len; i++)
            str1[i+(str1_len-1)] = str2[i];
    }

    public:
    
    static char* replace(const char lookup[], const char replace[], const char string[]) {
        short int len_lookup = len(lookup);
        short int len_replace = len(replace);
        short int len_string = len(string);
        char tmp[len_string*len_replace][len_replace];
        
        for(short int i = 0; i < len_string*len_replace; i++)
        {
            for(short int j = 0; j < len_replace; j++)
                tmp[i][j] = 0;    
        }
        
        short int skip = 0;
        for(short int i = 0; i < len_string; i++)
        {
            short int check = 0;
            
            for(short int j = 0; j < (len_lookup - 1); j++)
            {
                if(string[j+i] == lookup[j])
                    ++check;
                else
                    --check;
            }
            
            if(check == (len_lookup - 1))
            {
                for(short int j = 0; j < (len_replace - 1); j++)
                {
                    tmp[i][j] = replace[j];
                    skip = (len_lookup - 2);
                }
            }
            else
            {
                if(skip > 0)
                {
                    --skip;
                    continue;
                }
                
                tmp[i][0] = string[i]; 
            }   
        }
        
        short int count = 0;
        for(short int i = 0; i < len_string*len_replace; i++)
        {
            if(tmp[i] != 0)
            {
                for(short int j = 0; j < (len_replace - 1); j++)
                {
                    if(tmp[i][j] != 0)
                        ++count;
                    else
                        continue;
                }
            }
            else
                continue;
        }
    
        ++count; // For EOL character: 0x0;
        char *pChar = new char[count];
        
        for(short int i = 0; i < count; i++)
            pChar[i] = 0;
            
        for(short int i = 0; i < len_string*len_replace; i++)
            concat(pChar, tmp[i]);
    
        return pChar;
    }

};

int main()
{
    char str1[] = "ss ";
    char str2[] = "worldz AAA";
    
    std::cout << Str_Replace::replace("AA", "XXX", str2);
    
    int x; std::cin >> x;
    
    return 0;
}
