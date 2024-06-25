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
    vector<int>child(n);
    for(int i=0;i<n;i++){ /// taking input of givn child
        child[i]=i+1;
    }

    while(child.size()>1){  // codn till loop  work
    vector<int>s; // to contain remaining ele after printing ele

    for(int i=0;i<child.size();i++){
         if(i%2==1)
         cout<<child[i]<<" ";  // here at odd places even no is present
         else
         s.push_back(child[i]);  // now rem ele is present in s
      }

      if(child.size()%2==0) // if its even just do the process again 
      child=s;   // its for child to perform the same operation again 

      else{  // if child.size is odd
        int start=s.back();  // in even condn , one child will left always ,, usko store krke alag se print krenege
        s.pop_back(); //last ele ko remove kr diye
        child.clear();  // chid clear kyuki ab usme remaining ele jayega
        child.push_back(start); // ye last ele ko to daalenge jabtk perform kr rhr hai operation
        for(int x:s)
        child.push_back(x); // isme bacha hua sara ele jayega // agar child.push_back(start) nahi krte to eke ele rah jata
      }
    }
    cout<<child[0];
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