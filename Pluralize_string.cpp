#include <vector>
#include <string>
#include <iostream>
using namespace std;

std::vector<std::string> pluralize(std::vector<std::string> arr){
  	vector<bool> visited(arr.size(), false);
	vector<string> new_string;
	
	  for(int i =0 ; i< arr.size(); i++){
			int count = 0;
			if(visited[i]==false){
			    visited[i] = true;
				for(int j = i+1; j< arr.size(); j++){
					if(arr[j] == arr[i]){
						count++;
						visited[j]=true;
					}
				}
				if(count>=1){
					new_string.push_back(arr[i]+"s");
				} 
				if(count == 0){
				    new_string.push_back(arr[i]);}
				
			}
		}
	
	return new_string;
}
