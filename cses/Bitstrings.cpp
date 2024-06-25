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
#define ll long long int
#define mod 1000000007
using namespace std;
ll f(int a,int b){  // fn to return a^b
    if(b==0) return 1;  // base case
    ll res = f(a,b/2);  // divide and conq approach
    if(b&1){  // for odd
        return (((res*res)%mod)*a)%mod;
    }
    else  // even
    return (res*res)%mod;
}

int main(){
    int n;
    cin>>n; // input
    cout<<f(2,n)<<endl;
    
}