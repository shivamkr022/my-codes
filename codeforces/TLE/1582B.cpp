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
#include<cmath>
#include<climits>
using namespace std;
typedef long long ll;
int main(){
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int x0=0;
    int x1=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0) x0++;
        else if(arr[i]==1) x1++;
    }
    if(x0!=0){
    cout<<(1ll << x0) * (ll)x1<<endl;
    }
    else if(x0==0){
        cout<<x1<<endl;
       }
    }
    return 0;
}