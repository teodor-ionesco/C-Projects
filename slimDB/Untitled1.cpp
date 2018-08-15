#include "iostream"

int main()
{
    char replace[] = "DE";
    char with[] = "XXXX";
    char string[] = "ABCDEFGHIJ";
    char tmp[11];
    
    int rounds = 0;
    int count = 0;
    
    for(int i = 0; i < 11; i++)
    {
        bool repl = false;
        int c = -1;
        
        for(int j = 0; j < 2; j++)
        {
            if(string[i+j] == replace[j])
                ++c;
            else
                --c;
                
            if(j+1 == 2)
            {
                if(c == j)
                    repl = true;
                else
                    repl = false;    
            }
            
             std::cout << string[i+j] << ": " << c <<  '\n';
        }
        
       
        if(repl == true)
        {
            for(int j = 0; j < 4; j++)
            {
                tmp[i+j] = with[j];
                count = j-1;
                rounds = 1;
            }
        }
        else
        {
            if(rounds > 0)
            {
                rounds--;
                continue;
            }
            else
            {
                tmp[i+count] = string[i];    
            }
            //count = 0;  
        }
        
        //std::cout << "i:" << i << "repl: ";
        //std::cout << repl << '\n';
    }
    
    std::cout << tmp;
    
    int x; std::cin >> x;
    
    return 0;
}
