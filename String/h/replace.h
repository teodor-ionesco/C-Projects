namespace String 
{
    class Replace 
    {
        public:
            static const short int M_SIZE = 1025;
            static char tmpstr[];
            
            static void toNull() {
                for(short int i = 0; i < M_SIZE; i++)
                    Replace::tmpstr[i] = 0;    
            }
    };
    
    char Replace::tmpstr[M_SIZE];
    
    char* Replace(const char* lookup, const char* replace, const char* string)
    {
        short int len_lookup = Misc::len(lookup);
        short int len_replace = Misc::len(replace);
        short int len_string = Misc::len(string);
        char tmp[len_string*len_replace][len_replace+1];
        
        for(short int i = 0; i < len_string*len_replace; i++)
        {
            for(short int j = 0; j < (len_replace+1); j++)
                tmp[i][j] = 0;    
        }
        
        short int skip = 0;
        for(short int i = 0; i < len_string; i++)
        {
            if(skip > 0)
            {
                --skip;
                continue;
            }
            
            short int check = 0;
            
            for(short int j = 0; j < (len_lookup - 1); j++)
            {
                if(string[j+i] == lookup[j])
                    ++check;
                else
                    --check;
                    
                //std::cout << "i: " << i << "; string[" << j << "+" << i << "]; lookup: " << lookup[j] << "; check: " << check << '\n';
            }
            
            if(check == (len_lookup - 1) && len_lookup > 1)
            {
                if(len_replace > 1)
                {
                    for(short int j = 0; j < (len_replace - 1); j++)
                        tmp[i][j] = replace[j];
                }
                else
                    tmp[i][0] = 0;
                
                skip = (len_lookup - 2);
            }
            else
                tmp[i][0] = string[i];  
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
        
        Replace::toNull();
            
        for(short int i = 0; i < len_string*len_replace; i++)
        {
            if(tmp[i] != 0)
                Misc::concat(Replace::tmpstr, tmp[i]);
            else
                continue;
        }

        return Replace::tmpstr;
    }
    
    char* Replace(const char* lookup, const char* replace, const String::Init& object) {
        return Replace(lookup, replace, object.string);
    }
    
    char* Replace(const char* lookup, const String::Init& replace, const String::Init& string) {
        return Replace(lookup, replace.string, string.string);
    }
    
    char* Replace(const String::Init& lookup, const String::Init& replace, const String::Init& object) {
        return Replace(lookup.string, replace.string, object.string);
    }
    
    char* Replace(const String::Init& lookup, const char* replace, const String::Init& object) {
        return Replace(lookup.string, replace, object.string);
    }

    char* Replace(const String::Init& lookup, const char* replace, const char* string) {
        return Replace(lookup.string, replace, string);
    }
}
