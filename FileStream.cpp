#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{  
    ifstream file;
    string x;
    file.open("C:\\Users\\Andi\\Desktop\\Udemy\\Python-Notebook\\host.txt");
    if (!file) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    
    while (file >> x) {
        cout << x<<endl;
    }
    
    file.close();
    return 0;
}

