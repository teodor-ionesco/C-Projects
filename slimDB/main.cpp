#include "iostream"
#include "string"
#include "fstream"

using namespace std;

string gFName;

bool __fcheck(string);
void __fwrite();
string __fread();

bool __fcheck(char fname[])
{
    ofstream fh(fname, ios::app);
            fh.close();
    
    return (!fh) ? false : true;
}

void __fwrite()
{
    ofstream fh(gFName, ios::app);
             fh << "Write to file";
             fh.close();    
}

string __fread()
{
    char c;
    string tmp;
    
    ifstream fh(gFName);    
            while(fh.get(c))
            {
                tmp += c;
            }
            fh.close();
            
    return tmp;
}

int main()
{
    string tmp;
    
    cout << "Hello! What file would you like to open?" << endl;
    cin >> tmp;
    
    if(__fcheck(tmp) == false)
    {
        cout << "Such file does not exist." << endl;
        cin >> tmp;
        
        return 0;
    }
    
    gFName = tmp;
    
    cout << "Write to this file?" << endl;
    cin >> tmp;
    
    if(tmp == "yes")
    {
        __fwrite();
    }
    
    cout << "Read from this file?" << endl;
    cin >> tmp;
    
    if(tmp == "yes")
    {
        cout << __fread();
        cin >> tmp;
    }

    return 0;        
}
