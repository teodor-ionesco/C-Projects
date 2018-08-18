namespace LIB
{
    class Sort
    {
        static short int len(const char str[])
        {
            short int len = 0;
            
            for(short int i = 0; i >= 0; i++)
            {
                if(str[i] != '\0')
                    ++len;
                else
                    break;
            }
            
            return ++len;
        }
        
        static short int* explode(char* str)
        {
            short int len_str = Sort::len(str);
            char tmp[len_str];
            
            for(short int i = 0; i < len_str; i++)
                tmp[i] = 0;
                
            //LIB::String tmpstr = LIB::String::replace(",", "")
        }
        
        public:  
            static short int* asc(char* str)
            {
                
            }
    };
    
}
