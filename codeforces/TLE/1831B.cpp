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
    cin>>n;
    vector<int>arr1(n);
    vector<int>arr2(n);
    for(int i=0;i<n;i++){ //// input
        cin>>arr1[i];
    }
    for(int i=0;i<n;i++){ //// input
        cin>>arr2[i];
    } 
    unordered_map<int,int> count_cons1,count_cons2; /// map
    int idx =0;
    int val;
    int count;
    while(idx<n){
        val = arr1[idx];
        count =0;
        while(idx<n and arr1[idx]==val){
            count++;
            idx++;
        }
        count_cons1[val]=max(count_cons1[val],count);
    }
    idx =0;
    while(idx<n){
        val = arr2[idx];
        count =0;
        while(idx<n and arr2[idx]==val){
            count++;
            idx++;
        }
        count_cons2[val]=max(count_cons2[val],count);
    }
    int ans =0;
    for(auto ele :count_cons1){
        int val = ele.first;
        int val_count_in1= ele.second; // count of val in 1st array
        int val_count_in2= count_cons2[ele.first];  // count of first value in 2nd array
        ans = max(ans ,val_count_in1+val_count_in2);
    }
    for(auto ele :count_cons2){
        int val = ele.first;
        int val_count_in1= ele.second;
        int val_count_in2= count_cons1[ele.first];
        ans = max(ans ,val_count_in1+val_count_in2);
    }
    cout<<ans<<endl;
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

