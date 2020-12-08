#include <iostream>
#include <list>
#include <vector>
#include <math.h>

using namespace std;

class Point{
    private:
      int x;
      int y;
      
    public:
      void set_val(int x_val, int y_val){
        x = x_val;
        y = y_val;
    }
      void print_val(){
    	cout << "[" << x << "," << y << "]" << endl;
	}
	 int compute_d(Point a1, Point a2){
	 	return sqrt(pow((a2.x -a1.x),2)+ pow((a2.y -a1.y),2));
	 	
	 }
};

int main()
{
    vector<vector<int>> arr = {{1,0},{1,0}};

    std::list<Point> list;
    Point A;
    
    for(int i = 0; i<2; i++){
       for(int j = 0; j<2; j++){
           if(arr[i][j] == 1){
                A.set_val(i,j);
                list.push_back(A);
                
            }
        }
    }
    
    for(auto punto:list){
        punto.print_val();
    }

	
}

