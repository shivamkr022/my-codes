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
ll f(int a,int b){
    if(b==0) return 1;
    ll res = f(a,b/2);
    if(b%2==1){
        return (((res*res)%mod)*a)%mod;
    }
    else
    return (res*res)%mod;
}

int main(){
    int n;
    cin>>n;
    while(n--){
        int a,b;
        cin>>a>>b;
        cout<<f(a,b)<<endl;
    }
}