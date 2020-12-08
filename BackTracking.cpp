#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

void print(vector<int> arr){
    for(auto ele: arr){
        cout << ele;
    }
    cout <<"\n";
}

bool BoundFunction(int &i,vector<int> &subset, vector<int> &weights, int &limit){
    return (accumulate(subset.begin(), subset.end(),0) + weights[i] <= limit) && (accumulate(subset.begin(), subset.end(),0) + accumulate(weights.begin()+i, weights.end(),0) >= limit);
}

void backtracking(int i, vector<int> subset, vector<int> weights, int limit ){
    if(accumulate(subset.begin(), subset.end(),0) == limit){
        print(subset); 
        return;
    }
    
    if(BoundFunction(i, subset, weights, limit)){
        
        subset.push_back(weights[i]);
        backtracking(i+1, subset, weights, limit);
    
        subset.pop_back();
        backtracking(i+1, subset, weights, limit);
    }
    
    
}

int main()
{
  vector<int> weights{2,2,4};
  int sum{4};
  vector<int> subset;
  
  backtracking(0, subset, weights, sum);
}
