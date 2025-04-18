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
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++){
        v.push_back({arr[i],i+1});
    }

    multiset<int>s;
    for(int ele : arr){
        s.insert(ele);
    }

    int count =0;
    vector<int>ans;
    int sum = accumulate(arr.begin(),arr.end(),0LL);
    for(int i = 0; i < n; i++){
        s.erase(s.find(arr[i]));  // Temporarily remove current element
        int rem = sum - arr[i];
        if(rem % 2 == 0){
            int ele = rem / 2;
            if(s.find(ele) != s.end()){
                count++;
                ans.push_back(v[i].second); 
            }
        }
        s.insert(arr[i]);  // Re-insert current element
    }
    
    cout<<count<<endl;
    for(int ele :ans){
        cout<<ele<<" ";
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
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

