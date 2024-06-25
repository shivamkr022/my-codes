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

#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define debug(x) cout<<"errr----  "<< #x <<" " <<x<<endl 
#define print(v) do { \
                    cout << "vect--" << #v << " = [ "; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << v[i] << " "; \
                    } \
                    cout << " ]" << endl; \
                } while(0)
#else
#define debug(x)
#define print(v)
#endif
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
using namespace std;

/* write core logic here */
void solve(){

    int n;
    cin>>n; // input
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i]; // input
    int count=0;

    for(int i=0;i<n;i++){
      if(arr[i]==2) count++;  // count 2
    }
    int ans1=0;
    int ans =0;
    if(count==0) cout<<1<<endl;
    else if(count%2==1) cout<<-1<<endl;
    else{
      for(int i=0;i<n;i++){
      if(arr[i]==2) ans++;  // count 2 here also
      if(ans==count/2){
        cout<<i+1<<endl;  // answer
        return;
          }
        }
    }
}
/* logic ends */

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif
    int t;
    cin>>t;
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}

