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
    cin>>n;  // input 

    vector<int>ans;
    for(int i=0;i<n;i++){
        ans.push_back(i+1); // pushing ele in vector
    }

    int sum=0;
    for(int i=0;i<n;i++){
        sum+=ans[i];    // summation
    }

    int req= sum-1;
    int rem = req%n;   // observation aq to question

    int k=n-rem;
    ans[0]=k;
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";     /// ans
    }cout<<endl;
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
   // t = 1;
    while(t--){
        solve();
    }
return 0;
}

