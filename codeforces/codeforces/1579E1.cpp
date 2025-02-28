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
    vector<int>a;
    vector<int>b;
    int curr=-1;
    for(int i=0;i<n;i++){
        if(arr[i]>curr){
            b.push_back(arr[i]);
            curr=arr[i];
        }
        else{
            a.push_back(arr[i]);
            curr=arr[i];
        }
    }
    reverse(a.begin(),a.end());
    string s1;
    string s2;
    for(int ele:a){
        s1 += to_string(ele) + " ";
    }
    for(int ele:b){
        s2 += to_string(ele) + " ";
    }
    // cout<<s1<<endl;
    // cout<<s2<<endl;
    if(s1>s2){
        cout<<(s2+s1)<<endl;
    }
    else{
        cout<<(s1+s2)<<endl;
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

