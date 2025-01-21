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
    int n,m;
    cin>>n>>m;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<int>brr(m);
    for(int i=0;i<m;i++) cin>>brr[i];

    priority_queue<int>pqa,pqb;
    for(int ele :arr){
        pqa.push(ele);
    }
    for(int ele :brr){
        pqb.push(ele);
    }
    while(!pqa.empty()){
        if(pqb.empty() or pqb.size()>pqa.size()){
            cout<<"NO"<<endl;
            return;
        }
        int b = pqb.top();
        pqb.pop();
        if(b<pqa.top()){
            cout<<"NO"<<endl;  // not possible to create 
            return;
        }
        if(b==pqa.top()){  // match so delete 
            pqa.pop();
        }
        else{  // ele diff should be 1
            pqb.push(b/2);
            pqb.push((b+1)/2);
        }
    }
    if(!pqb.empty()) {
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
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

