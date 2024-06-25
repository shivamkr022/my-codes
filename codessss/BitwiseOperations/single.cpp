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

int main(){
    int arr[]={1,3,5,6,3,1,5};
    int n=7;
    int ans=0;
    for(int i=0;i<n;i++){
       ans = ans^arr[i];
    }
  cout<<ans<<endl;

}