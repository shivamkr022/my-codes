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
    vector<int>songs(n);
    for(int i=0;i<n;i++) cin>> songs[i];
    set<int>s;
    int ans =0;
    int i=0,j=0;
    while(i<n and j<n){
        while(j<n && !s.count(songs[j])){  // if its not repeated song
            s.insert(songs[j]); // if we iterate next then we an check its repeated or not
            int x=s.size();
            ans =max(ans,x);  // ans 
            j++;
        }
        while(j<n && s.count(songs[j])){ // it means the song is repeated
            s.erase(songs[i]);
           //s.clear();
            i++;
        }
    }
    cout<<ans<<"\n";

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

