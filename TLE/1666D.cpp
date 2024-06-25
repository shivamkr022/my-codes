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
    string s,t;
    cin>>s>>t;
    
    int n = s.length();
    int m = t.length();
    int i=0;
    int j=0;

    map<char,int>mp1;
    map<char,int>mp2;
    for(char ch:s){       // freq of each char of s
        mp1[ch]++;
    } 
    for(char ch:t){
        mp2[ch]++;    //freq of each char of t
    }     
    while(i<n && j<m){
        if(s[i]==t[j]){
            if(mp1[s[i]]<mp2[t[j]]){  // if freq is less we cnan never obtained t
                break;
            }
            if(mp1[s[i]]==mp2[t[j]]){ // if freq matches it can form t
                  mp2[t[j]]--;
                  j++;
            }
        }
        mp1[s[i]]--;
        i++;
    }
    if(j==t.size()){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
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

