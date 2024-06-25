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
    int n; // size of input
    cin>>n;

    stack<pair<int,int>> st; // pair of stack to store ele with index
    vector<int>arr(n);
    for(int i=0;i<=n;i++) cin>>arr[i];  // input of given array

    for(int i=0;i<n;i++){
        while(st.size()>0 && st.top().first>=arr[i]){  // condn for removing an ele
            st.pop(); // pop till top ele become < arr[i]
        }
        if(st.size()>0){  // after pop if ele is prsent in st // print the index of top ele
            cout<<st.top().second<<" ";
            st.push({arr[i],i+1});
        }
        else{  // stack is empty
            cout<<0<<" ";
            st.push({arr[i],i+1});
        }
      //  st.push({arr[i],i+1}); // if stack becomes empty or st.top()>arr[i] // then we push the ele in stack
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

