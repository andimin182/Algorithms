#include <iostream>

#include <vector>
using namespace std;


void print(vector<int> &array){
	if(array.size()>=1){
	
       for(auto i : array){
           cout << i;
       }   
     }else{
     	cout<< 0;
	 }
    
    cout <<"\n";
}

int recursion(vector<int> &array, vector<int> &subset, int i){
    if(i == array.size()){
	   print(subset);
	   return 0;
    }
    
    //cout << i <<"\n";
    subset.push_back(array[i]);
    recursion(array, subset, i+1);
    //cout << "2r";
    subset.pop_back();
    recursion(array, subset, i+1);
    //cout << "out";
}

int main()
{
    vector<int> test{1,2,3,4};
    int count = 0;
    vector<int> subset;
    
    int a = recursion(test, subset, 0);
   
    
    return 0;
}

