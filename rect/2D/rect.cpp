#include "iostream"

using namespace std; 

typedef unsigned int UI;

class RECT
{
    public: 
        RECT(UI s, UI l, UI h)
        {
            this -> start = s;
            this -> length = l;
            this -> height = h;
        }
        
        void drawRect() const
        {
            if(this -> length < 2 || this -> height < 2)
            {
                cout << "Width and Height must be at least 2. Otherwise it's a line :)";
                
                return;
            }
            
            this -> drawWidth();
                cout << endl;
            this -> drawHeight();
            this -> drawWidth();
        }
        
        UI getStart() const {return this->start;}
        UI getLength() const {return this->length;}
        UI getHeight() const {return this->height;}
    
    private:
        UI start, length, height;

        void drawStart() const
        {
            for(UI i = 1; i <= start; i++)
            {
                cout << " ";
            }    
        }
        
        void drawWidth() const
        {
            this -> drawStart();
            
            for(UI j = 1; j <= length; j++)
            {
                cout << "*";
            }
        }
    
        void drawHeight() const
        {
            for(UI k = 1; (k <= height - 2); k++)
            {
                this -> drawStart();
                
                cout << "*";
                
                for(UI m = 1; m <= (this->length - 2); m++)
                {
                    cout << " ";
                }
                
                cout << "*";
                cout << endl;
            }    
        }
};

int main()
{
    UI start;
    UI length;
    UI height;
    
    start:
        cout << "Input start: ";  cin >> start;
        cout << "Input width: ";  cin >> length;
        cout << "Input height: ";  cin >> height;
    
        RECT MyRect(start, length, height);
        
        MyRect.drawRect();
        
        char tmp; cin >> tmp;
        
        cout << endl << endl;
    goto start;
    
    return 0;    
}
