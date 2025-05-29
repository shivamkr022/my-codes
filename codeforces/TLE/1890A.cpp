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
    for(int i=0;i<n;i++) cin>>arr[i];  // input

    vector<int>temp; // to store the freq of eac ele 

    unordered_map<int,int>mp;
    
    for(auto x:arr){  // stored each ele for given arr in map
        mp[x]++;
    }

    for(auto y:mp){       //  store freq of each ele in the temp 
        temp.push_back(y.second);
    }
    sort(temp.begin(),temp.end());

    if(temp.size()>2) cout<<"NO"<<endl;  // just a lot of observation // cant be possible that alt sum is equal
    else if(temp.size()<=2 and temp[temp.size()-1]-temp[0]<=1) cout<<"YES"<<endl;  // just a lot of observation 
    else if(temp.size()<=2 and temp[temp.size()-1]-temp[0]>=2) cout<<"NO"<<endl;   // just a lot of observation 
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

