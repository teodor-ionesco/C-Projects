namespace String
{
    class Misc 
    {
        public:
            static short int len(const char*);
            static void concat(char*, const char*);
            static void toNull(char*);
    };    
    
    ////////////////////////////////////////////
    
    short int Misc::len(const char * str) {
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
    
    void Misc::concat(char* str1, const char* str2) {
        int str1_len = Misc::len(str1);
        int str2_len = Misc::len(str2);
        
        for(int i = 0; i < str2_len; i++)
            str1[i+(str1_len-1)] = str2[i];
    }

    void Misc::toNull(char* str) {
        short int len_str = Misc::len(str);
        
        for(short int i = 0; i < len_str; i++)
            str[i] = 0;
    }
}
