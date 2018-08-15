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
            
            for(short int i = 0; i < MAX_SIZE; i++)
            {
                if(str[i] != '\0')
                    length++;
                else
                    return ++length;
            }
        }

        // Append new characters to current string
        void _append(const char str[])
        {
            short int start = this -> __getLength(this -> string)-1;
            short int length = this -> __getLength(str);
            
            for(short int i = 0; i < length; i++)
                this -> string[start+i] = str[i];
        }
        
        void _flush()
        {
            for(short int i = 0; i < String::M_SIZE; i++)
                this -> string[i] = 0;    
        }
        
        public:
            // Constants.
            static const short int MAX_SIZE = String::M_SIZE;
            
            static void _flushTMP()
            {
                for(short int i = 0; i < String::MAX_SIZE; i++)
                    String::tmp_string[i] = 0;
            }
            
            // str = "1234567..."
            void operator=(char str[]) {
                this -> _flush();
                
                short int length = this -> __getLength(str);
                
                for(short int i = 0; i < length; i++)
                    this -> string[i] = str[i];
            }
            
            void operator=(String &object) {
                this -> operator=(object.string);
            }
            
            //friend char* operator<<(std::ostream &, String &);
            friend std::ostream& operator<<(std::ostream &, String &);
            friend char* operator+(String&, char []);
            friend char* operator+(char [], String&);
            
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
        String::_flushTMP();
        
        for(short int i = 0; i < string_object.M_SIZE; i++)
            String::tmp_string[i] = string_object.string[i];
            
        short int start = string_object.__getLength(String::tmp_string)-1;
        short int length = string_object.__getLength(string_array);
        
        for(short int i = 0; i < length; i++)
            String::tmp_string[start+i] = string_array[i];
            
        return String::tmp_string;
    }
    
    char* operator+(char string_array[], String& string_object) {
        String::_flushTMP();
        
        short int length = string_object.__getLength(string_array);
        
        for(short int i = 0; i < length; i++)
            String::tmp_string[i] = string_array[i];
            
        short int start = length-1;
                  length = string_object.__getLength(string_object.string);

        for(short int i = 0; i < length; i++)
            String::tmp_string[start+i] = string_object.string[i];
            
        return String::tmp_string;
    }
    
    /*char* operator<<(std::ostream &ostream_object, String &string_object) {
        ostream_object << string_object.string;
        return string_object.string;
    }*/
}
