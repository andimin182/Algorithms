#include <iostream>
#include <string>

using namespace std;

string transform(string &s, int i, int j){
    bool condition = true;
    
    while(condition){
        if(s[i] =='A' && s[j] =='B'){
        
            s.erase(i,j+1);
            if(s.length() ==0){
                return "Empty";
            }
            if(s.length() ==1){
                return s;
            }
            transform(s, i, j);
        }
        
        i++;
        j++;
        if(j >= s.length()){
            condition = false;
            return s;
        }
        transform(s, i, j);
    }

    
    return s;
}

int main()
{   
    string a = {"ABC"};
    cout<< transform(a, 0, 1);

    return 0;
}

