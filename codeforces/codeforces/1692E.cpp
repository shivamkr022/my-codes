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

int longestSubarrayWithSumX(vector<int>& arr, int x) {
    unordered_map<int, int> px;
    int sum = 0, maxLength = 0;
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        if (sum == x) {
            maxLength = i + 1;
        }
        if (px.find(sum - x) != px.end()) {
            maxLength = max(maxLength, i - px[sum - x]);
        }
        if (px.find(sum) == px.end()) {
            px[sum] = i;
        }
    }
    return maxLength;
}
/* write core logic here */
void solve(){
    int n ,x;
    cin>> n >> x;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>> arr[i];
    int sum =0;
    for(int ele :arr) sum+=ele;
    if(sum==x){
        cout<<0<<endl;
        return;
    }
    if(sum<x){
        cout<<-1<<endl;
        return;
    }
    int ans = longestSubarrayWithSumX(arr,x);
    cout<<(n-ans)<<endl;
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

