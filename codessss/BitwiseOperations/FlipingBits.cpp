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
int f(int n){
  int x=n;
  n=n|(n>>1);
  n=n|(n>>2);
  n=n|(n>>4);  // doing this process to make every bit set bits
  n=n|(n>>8);
  n=n|(n>>16);
  int ans = n^x;
  return ans;
}

int main(){
cout<<f(11)<<endl;
}