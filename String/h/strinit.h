namespace String
{
    class Init
    {
        static const short int M_SIZE = 1025;
        
        char string[M_SIZE];
        char tmp[];
        
        public:
            Init(const char*);
            Init(){};
            ~Init(){}
            
            void operator= (const char*);
            
            friend char* operator+ (Init&, const char*);
            friend char* operator+ (const char*, Init&);
            friend char* operator+ (Init&, Init&);
            
            friend std::ostream& operator<< (std::ostream&, Init&);
            
            friend char* String::Replace(const char*, const char*, const Init&);
            friend char* String::Replace(const char*, const Init&, const Init&);
            friend char* String::Replace(const Init&, const Init&, const Init&);
            friend char* String::Replace(const Init&, const char*, const Init&);
            friend char* String::Replace(const Init&, const char*, const char*);   
    };
    
    Init::Init(const char* str) {
        this -> operator=(str);
    }
    
    void Init::operator= (const char* str) {
        short int len_str = Misc::len(str);

        for(short int i = 0; i < len_str; i++)
            this -> string[i] = str[i];
    }
    
    char* operator+ (Init& object, const char* str) {
        short int len_object = Misc::len(object.string);
        short int len_str = Misc::len(str);
                  object.tmp[(len_object + len_str)];
        
        Misc::toNull(object.tmp);        
        Misc::concat(object.tmp, object.string);
        Misc::concat(object.tmp, str);
        
        return object.tmp;
    }
    
    char* operator+ (const char* str, Init& object) {
        short int len_object = Misc::len(object.string);
        short int len_str = Misc::len(str);
        
        Misc::toNull(object.tmp);        
        Misc::concat(object.tmp, str);
        Misc::concat(object.tmp, object.string);
        
        return object.tmp;
    }
    
    char* operator+ (Init& object1, Init& object2) {
        short int len_object1 = Misc::len(object1.string);
        short int len_object2 = Misc::len(object2.string);
                  object1.tmp[(len_object1 + len_object2)];
        
        Misc::toNull(object1.tmp);        
        Misc::concat(object1.tmp, object1.string);
        Misc::concat(object1.tmp, object2.string);
        
        return object1.tmp;
    }
    
    std::ostream& operator<< (std::ostream& os, Init& object) {
        return os << object.string;
    }
}
