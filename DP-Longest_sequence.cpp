#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(vector<int> arr){
	auto it = max_element(begin(arr), end(arr));
	cout<< *it;
}

void longest_sequence(vector<int> &array, vector<int> &subproblem){
	for(int k=0; k<array.size(); k++){
		subproblem[k]=1;
		for(int i=0; i<k; i++){
			if(array[i]<array[k]){
				subproblem[k] = max(subproblem[k], subproblem[i]+1);
			}
		}
	}
	print(subproblem);
}

int main(){
	
	vector<int> arr{8,2,9,10,11,5,6};
	vector<int> subproblem(arr.size(),0);
	//subproblem[0]=1;
	//cout << subproblem[0];
	longest_sequence(arr, subproblem);
	
	
}
