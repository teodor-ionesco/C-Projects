namespace __LIB
{
    ////////////////////////////
    class String
    {
        public:
            static const short int MAX_SIZE = 1024;
            
            String(char []);
            ~String(){}
            
            inline char* ret();

            void operator=(char []);
            
        private:
            char string[MAX_SIZE];
            
            short int __getSize(char []);
    };
    ////////////////////////////
    String::String(char str[])
    {
        this -> operator=(str);
    }
    ////////////////////////////
    short int String::__getSize(char str[])
    {
        short int length = 0;
        
        for(short int i = 0; i < MAX_SIZE; i++)
        {
            if(str[i] != '\0')
                length++;
            else
                return ++length;
        }
    }
    ////////////////////////////
    void String::operator=(char str[])
    {
        short int length = this -> __getSize(str);
        
        for(short int i = 0; i < length; i++)
            this -> string[i] = str[i];
    }
    ////////////////////////////
    ////////////////////////////
    inline char* String::ret()
    {
        return this -> string;    
    }
    
}
