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
    int n,x;
    cin>>n>>x;
    vector<pair<int,int>> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i].first;  // taking input of number only not index
        nums[i].second=i+1;  // answer is in 1 index 
    }
    sort(nums.begin(),nums.end());

    for(int i=0;i<n;i++){
        int rem = x-nums[i].first;
        for(int j=i+1, k=n-1; j<k; j++){
             while(nums[j].first+nums[k].first>rem) 
             k--;
             if(j<k and nums[j].first+nums[k].first==rem ){
                cout<<nums[i].second<<" " << nums[j].second<< " "<< nums[k].second;
                return ;
             }
        }
    }
    cout<<"IMPOSSIBLE";

}
/* logic ends */

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif
    int t;
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

