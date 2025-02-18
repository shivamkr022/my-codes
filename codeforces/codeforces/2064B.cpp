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
    // int lans =-1;
    // int rans = -1;
    // int k=0;
    // int mxl =0;
    // map<int,int>mp;
    // for(int ele:arr)mp[ele]++;

    // for(int i=0;i<n;i++){
    //     k=max(k,i);
    //     while(k<n and mp[arr[k]]==1){
    //         k++;                               // my approach
    //     }
    //     if(k-i>mxl){
    //         mxl = k-i;
    //         lans =i;
    //         rans =k-1;
    //     }
    // }
    // if(lans==-1){
    //     cout<<0<<endl;
    // }
    // else{
    //     cout<<lans+1<<" "<<rans+1<<" "<<endl;
    // }
    vector<int> freq(n + 1);
    for (int x : arr) freq[x]++;

    vector<int> len(n + 1);
    len[0] = freq[arr[0]] == 1;
    for (int i = 1; i < n; i++)
        if (freq[arr[i]] == 1)
            len[i] = len[i - 1] + 1;
          //  print(len);
    
    int mx = *max_element(len.begin(), len.end());
    if (mx == 0){
        cout << "0\n";       // learnt approach from solution
        return;
    }

    for (int i = 0; i < n; i++){
        if (len[i] == mx){
            cout << i - len[i] + 2 << " " << i + 1 << "\n";
            return;
        }
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

