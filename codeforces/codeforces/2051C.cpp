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
    int n,m,k;
    cin>>n>>m>>k;
    vector<int>arr(m);
    for(int i=0;i<m;i++) cin>>arr[i];
    vector<int>qq(k);
    for(int i=0;i<k;i++) cin>>qq[i];

    string str0(m,'0');
    string str1(m,'1');

    if((n-1)>k){
        cout<<str0<<endl;
        return; 
    }
    if((n-1)<k){
        cout<<str1<<endl;
        return;
    }
    set<int>st;
    for(int ele :qq){
        st.insert(ele);
    }
    string anss ="";
    int sz = st.size();
    for(int i=0;i<m;i++){
        if(sz==(n-1) and st.find(arr[i]) == st.end()){// not prsent
        anss+='1';
        }
        else{
            anss+='0';
        }
    }
        cout<<anss<<endl;
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

