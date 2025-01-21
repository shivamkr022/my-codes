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
    map<int,int>mp;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        mp[arr[i]]++;
    }
    int freq = 0;
    for(auto ele :mp){
        freq = max (freq , ele.second);
    }
    if(freq<2){
        cout<<-1<<endl;
        return;
    }
    int ple = 0;
    for(auto ele :mp){
        if(ele.second>=2){
            ple = max(ple ,ele.first);
        }
    }
    int removed = 0;
    for(int i = 0; i < n; i++) {    // Remove two elements equal to `ple` from the array
        if(arr[i] == ple && removed < 2) {
            arr[i] = -1; 
            removed++;
        }
    }
    vector<int> newArr;  // Rebuild the array after removal
    for(int ele : arr) {
        if(ele != -1) {
            newArr.push_back(ele);
        }
    }
    //debug(ple);
    // print(newArr);
    if(newArr.size() < 2) {
        cout << -1 << endl;
        return;
    }
    int tar = 2 * ple;
    sort(newArr.begin(), newArr.end());
    for(int i = 1; i < newArr.size(); i++) {
        if(abs(newArr[i] - newArr[i-1]) < tar) {
            cout << ple << " " << ple << " " << newArr[i-1] << " " << newArr[i] << endl;
            return;
        }
    }
    cout << -1 << endl;
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
    while(t--){
        solve();
    }
    return 0;
}

