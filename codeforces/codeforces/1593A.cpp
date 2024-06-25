/*
  ------------------------------------------
 |                                        |
 |      Code Crafted by Shivam     |
 |                                        |
  ------------------------------------------
    \        ,     ,        /
      \      |     |      /
         \   \_/   /
           \  -----  /
             \_/
  
  Happy coding! 
*/

/* includes and all */
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>
using namespace std;
int solveSingle(int best, int k, int m){ // fn return canditates need vote 
	return max(0, max(k, m) + 1 - best);
}

int main(){
    int t;
	cin >> t;
	while (t--){
		int a, b, c;
		cin >>a>>b>>c;
		cout<<solveSingle(a, b, c) <<" "<< solveSingle(b, a, c) <<" "<< solveSingle(c, a, b) << '\n';
	}
}