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
  n=n|(n>>1);
  n=n|(n>>2);
  n=n|(n>>4);  // doing this process to make every bit set bits
  n=n|(n>>8);
  n=n|(n>>16);
 return (n+1)>>1;
}

int main(){
    int x = 11;
    int temp=0; // to store last non zero number
    while(x){
        temp=x;
        x= (x&(x-1));
    }
  cout<<temp<<"\n";
  cout<<f(11)<<endl;
}