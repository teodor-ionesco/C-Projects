#include "iostream"

using namespace std;

typedef unsigned int UI;

class TRIANGLE
{   
    public:
        TRIANGLE(UI l, UI start)
        {
            this -> l = l;
            this -> start = start;
            this -> diff = 0;
        }
        
        void draw()
        {
            for(UI j = 0; j < this -> l; j++)
            {
                drawStart();
                drawBody();
            }
        }
        
    private:
        UI l, start;
        UI diff;
        
        void drawStart()
        {
            for(UI k = 0; k < this -> start; k++)
            {
                cout << " ";
            }    
        }
        
        void drawBody()
        {
            if(this -> diff == 0)
            {
                cout << "*" << endl;
                
                this -> diff++ ;
                
                return;
            }
            
            if(this -> diff == (this -> l - 1))
            {
                for(UI m = 0; m < this -> l; m++)
                {
                    cout << "*";
                } 
                
                cout << "*";
                
                return;
            }
            
            cout << "*";
            
            for(UI i = 0; i < this -> diff; i++)
            {
                cout << " ";
            }
            
            cout << "*" << endl;
            
            this -> diff++;
            
            return;
        }
};

int main()
{    
    UI l, start;
    
    program:
        cout << "Start: "; cin >> start;
        cout << "L: "; cin >> l;
        
        TRIANGLE myTriangle(l, start);
        myTriangle.draw();
        
        char tmp; cin >> tmp;
    goto program;
    
    return 0;    
}
