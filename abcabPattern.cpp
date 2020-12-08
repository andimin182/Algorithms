#include <string>
#include <vector>
using namespace std;

std::string abacabaPattern(int n) {
	vector<string> memo;
	vector<string> str(n);
	str[0]= "A";
	
  if(!memo[n].empty()){
		return memo[n];
	} else{
		 if(n <=1){
			 return str[0] ; //initialized to A
		 } else{
		     str[n] = abacabaPattern(n-1) + char(64+n) + abacabaPattern(n-1);
		     memo[n] = str[n] ;
		     return str[n];}
	}
	
	
}
