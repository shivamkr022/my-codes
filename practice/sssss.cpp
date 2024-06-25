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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int count = 0;
    // Initial count of 'W' in the first window
    for(int i = 0; i < k; i++){
        if(s[i] == 'W'){
            count++;
        }
    }
    // Set the initial answer to the count of the first window
    int ans = count;

    int i = 1; // Start of the window
    int j = k; // End of the window

    // Use a while loop to slide the window across the string
    while(j < n){
        // Update count based on the outgoing and incoming characters
        if(s[i - 1] == 'W') count--;
        if(s[j] == 'W') count++;

        // Update the minimum count found so far
        ans = min(ans, count);

        // Move the window
        i++;
        j++;
    }
    cout << ans << endl;
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
