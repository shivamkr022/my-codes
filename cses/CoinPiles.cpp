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
typedef long long ll;

int main(){
    int t;
    cin>>t;
    while(t--){
    int a,b;
    cin>>a>>b;
    if((a+b)%3==0 && max(a,b)<=2*min(a,b)) cout<<"YES"<<endl;  // condition 
    else cout<<"NO"<<endl;
    }
 return 0;
}