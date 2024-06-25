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
ll f(int base,int expo,int m){
    if(expo==0) return 1;
    ll res = f(base,expo/2,m);
    if(expo%2==1){
        return (((res*res)%m)*base)%m;
    }
    else
    return (res*res)%m;
}

int main(){
    int n;
    cin>>n;
    while(n--){
        int a,b,c;
        cin>>a>>b>>c;
        int expo=f(b,c,mod-1);
        cout<<f(a,expo,mod)<<endl;
    }
}