namespace LIB
{
    ////////////////////////////
    class String
    {
        // Constants.
        static const short int M_SIZE = 1024;
        
        // Vars.
        char string[M_SIZE];
        static char tmp_string[M_SIZE];
        
        // Get length of str[]
        short int __getLength(const char str[]) {
            short int length = 0;
            
            for(short int i = 0; i <= MAX_SIZE; i++)
            {
                if(str[i] != '\0')
                    length++;
                else
                    return ++length;
                    
                if(i == MAX_SIZE)
                    throw std::runtime_error("MAX_SIZE has been exceeded.");
            }
        }
        
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
        
        static void concat(char* str1, char* str2)
        {
            int str1_len = String::len(str1);
            int str2_len = String::len(str2);
            
            for(int i = 0; i < str2_len; i++)
                str1[i+(str1_len-1)] = str2[i];
        }
        
        // Clear this -> string
        void _flush()
        {
            for(short int i = 0; i < String::M_SIZE; i++)
                this -> string[i] = 0;    
        }
        
        public:
            // Constants.
            static const short int MAX_SIZE = String::M_SIZE;
            
            // Clear String::tmp_string
            static void _flushTMP() {
                for(short int i = 0; i < String::MAX_SIZE; i++)
                    String::tmp_string[i] = 0;
            }

            static char* replace(const char lookup[], const char replace[], const char string[]) {
                short int len_lookup = String::len(lookup);
                short int len_replace = String::len(replace);
                short int len_string = String::len(string);
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
                char *pChar = new char[count];
                
                for(short int i = 0; i < count; i++)
                    pChar[i] = 0;
                    
                for(short int i = 0; i < len_string*len_replace; i++)
                {
                    if(tmp[i] != 0)
                        String::concat(pChar, tmp[i]);
                    else
                        continue;
                }

                return pChar;
            }
            
            // str = "1234567..."
            void operator=(char str[]) {
                short int length = this -> __getLength(str);
                
                this -> _flush();
                
                for(short int i = 0; i < length; i++)
                    this -> string[i] = str[i];
            }
            
            void operator=(String &object) {
                this -> operator=(object.string);
            }
            
            friend std::ostream& operator<<(std::ostream &, String &);
            friend char* operator+(String&, char []);
            friend char* operator+(char [], String&);
            friend char* operator+(String&, String&);
            
            // String str = "23456789"
            String(char str[]) {
                this -> operator=(str);
            }
            ~String(){}
    };
    ////////////////////////////
    char String::tmp_string[String::MAX_SIZE];
    ////////////////////////////
    
    std::ostream& operator<<(std::ostream &ostream_object, String &string_object) {
        return ostream_object << string_object.string;
    }
    
    char* operator+(String& string_object, char string_array[]) {
        string_object.__getLength(string_array);
        String::_flushTMP();
        
        for(short int i = 0; i < string_object.M_SIZE; i++)
            String::tmp_string[i] = string_object.string[i];
            
        short int start = string_object.__getLength(String::tmp_string)-1;
        short int length = string_object.__getLength(string_array);
        
        if((start + length) > String::MAX_SIZE)
            throw std::runtime_error("MAX_SIZE has been exceeded.");
        
        for(short int i = 0; i < length; i++)
            String::tmp_string[start+i] = string_array[i];
            
        return String::tmp_string;
    }
    
    char* operator+(char string_array[], String& string_object) {
        string_object.__getLength(string_array);
        String::_flushTMP();
        
        short int length = string_object.__getLength(string_array);
        
        for(short int i = 0; i < length; i++)
            String::tmp_string[i] = string_array[i];
            
        short int start = length-1;
                  length = string_object.__getLength(string_object.string);

        if((start + length) > String::MAX_SIZE)
            throw std::runtime_error("MAX_SIZE has been exceeded.");

        for(short int i = 0; i < length; i++)
            String::tmp_string[start+i] = string_object.string[i];
            
        return String::tmp_string;
    }
    
    char* operator+(String& str1, String& str2) {
        String::_flushTMP();
        
        short int str1len = str1.__getLength(str1.string);
        short int str2len = str1.__getLength(str2.string);
        
        if(str1len + str2len > String::MAX_SIZE)
            throw std::runtime_error("MAX_SIZE has been exceeded.");
        
        for(short int i = 0; i < str1len; i++)
            String::tmp_string[i] = str1.string[i];
            
        short int start = str1len-1;
        
        for(short int i = 0; i < str2len; i++)
            String::tmp_string[start+i] = str2.string[i];
            
        return String::tmp_string;
    }
}
