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

int f(int x){
    if(x<0) return -1;
    int count = 0;
    for(int i=5;x/i>=1;i*=5){   // legend method
        count+=x/i;
    }
    return count;
}

int main(){
    int x;
    cin>>x;
    cout<<f(x)<<"\n";
}