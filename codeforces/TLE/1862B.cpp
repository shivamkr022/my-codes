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

    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];  // input of vector

    vector<int>ans;
    
    ans.push_back(arr[0]);
    for(int i=1;i<arr.size();i++){
        if(arr[i-1]>arr[i]){  // we push back two ele in this case
            if(arr[i]>1){
            ans.push_back(arr[i]-1);
            }else{
                ans.push_back(arr[i]);
            }
            ans.push_back(arr[i]); // push back one ele 
        }
        else
        ans.push_back(arr[i]);
    }

    cout<<ans.size()<<endl;  // length of ans
    for(int i=0;i<ans.size();i++){  // ele of ans //just printing
        cout<<ans[i]<<" ";
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
   // t = 1;
    while(t--){
        solve();
    }
return 0;
}

