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
    string str = to_string(n);
    int last = 0;
    string a = "";
    string b = "";

    for(int i = 0; i<str.size(); i++){
        char ch = str[i];
        int xx = ch - '0';
        int half = xx / 2;
        if(xx & 1){
            if(last == 0){
                a += to_string(half + 1);
                last ^= 1; 
                b += to_string(half);
            }
            else{
                b += to_string(half + 1);
                last ^= 1;
                a += to_string(half);
            }
        }
        else{
            a += to_string(half);
            b += to_string(half);
        }
    }
    int aa = 0;
    int bb = 0;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for(int i = 0; i<a.size(); i++){
        aa += (a[i] - '0') * pow(10,i);
        bb += (b[i] - '0') * pow(10,i);
    }
    cout<<aa<<" "<<bb<<endl;
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

