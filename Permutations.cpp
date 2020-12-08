#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> array){
    for(auto ele:array){
        cout << ele;
    }
   
    cout <<"\n";
}

void SearchPermutation(int n, vector<int> &permutation, vector<bool> &fixed, vector<int> &set){
    if(permutation.size()== n){
        print(permutation);
        return;
       
    }
    for(int i = 0; i< n; i++){
        if(fixed[i]==true) continue;
        fixed[i] = true;
        permutation.push_back(set[i]);
        SearchPermutation(n, permutation, fixed, set);
        fixed[i]=false;
        permutation.pop_back();
    }
}

int main()
{
    vector<int> set{1,2,3,9};
    vector<bool> fixed(set.size(), false);
    vector<int> permutation;
   
    SearchPermutation(set.size(), permutation, fixed, set);

    return 0;
}
