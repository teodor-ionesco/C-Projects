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
            
            /*
            *
            *   BAD DESIGN! TRYING WITH MULTIDIMENSIONAL VECTORS TOMORROW.
            *
            */
            static char* replace(const char lookup[], const char replace[], String &object) {
                short int len_lookup = (object.__getLength(lookup)) - 1;
                short int len_replace = (object.__getLength(replace)) - 1;
                short int len_string = object.__getLength(object.string);
 
                //if(len_lookup == 1)
                  //  len_lookup++;
 
                char tmp[String::MAX_SIZE];
                
                short int count = 0;
                short int rounds = 0;
                
                for(short int i = 0; i < len_string; i++)
                {
                    bool repl = false;
                    short int c = -1;
                    
                    for(short int j = 0; j < len_lookup; j++)
                    {
                        if(object.string[i+j] == lookup[j])
                            ++c;
                        else
                            --c;
                            
                        if(j+1 == len_lookup)
                        {
                            if(c == j)
                                repl = true;
                            else
                                repl = false;    
                        }
                    }
                    
                    if(repl == true)
                    {
                        for(short int j = 0; j < len_replace; j++)
                        {
                            tmp[i+j] = replace[j];
                            
                            if(j == 0)
                            {
                                rounds = 0;
                                count = j;
                            }
                            else
                            {
                                rounds = len_lookup-1;
                                count = j-1;
                            }
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
                            tmp[i+count] = object.string[i];
                        }
                    }
                }
                
                std::cout << tmp;
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
