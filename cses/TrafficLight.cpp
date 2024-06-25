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
    int x,n;
    cin>>x>>n;
    set<int>s;  // store each ele
    multiset<int>len; // store the length
    s.insert(0);  // we add 0 and x
    s.insert(x);
    len.insert(x-0);
    for(int i=0;i<n;i++){
       int val;
       cin>>val; // each ele of the give array
       s.insert(val); // add each value in the set
       auto itr = s.find(val);  // posn of each value;
       int nextval = *next(itr);  // value just next of the current posn
       int prevval = *prev(itr);
       len.erase(len.find(nextval-prevval));  // if next-prev in length remove the value
       len.insert(val-prevval);
       len.insert(nextval-val);
       cout<<*len.rbegin()<<" ";
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
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

