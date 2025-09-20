/*
  ------------------------------------------
 |                                        |
 |      Code Crafted by Shivam             |
 |                                        |
  ------------------------------------------
    \        ,     ,        /
      \      |     |      /
         \   \_/   /
           \  -----  /
             \_/
  
  Happy coding! 
*/

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

struct node{
    int sum;
    node (){
        sum = 0;
    }
};

node merge(node a ,node b){
    node ans;
    ans.sum = a.sum + b.sum ;
    return ans;   // ✅ missing earlier
}

node tree[4*200000];
vector<int> arr;   // ✅ make global for build()

// Build -> Update -> Query

void build(int idx ,int l ,int r){ // Build
    if(l==r){
        tree[idx].sum = arr[l];   // ✅ use array value
        return ;
    }
    int mid  = (l+r)/2;
    build(2*idx,l,mid);
    build(2*idx+1,mid+1,r);
    tree[idx] = merge(tree[2*idx],tree[2*idx+1]);
}

void update(int idx ,int l ,int r ,int pos ,int val){ // update 
    if(pos < l or pos > r){
        return ;
    }
    if(l==r){
        tree[idx].sum = val;   // ✅ set value, not add
        return ;
    }
    int mid  = (l+r)/2;
    update(2*idx,l,mid,pos,val);
    update(2*idx+1,mid+1,r,pos,val);
    tree[idx] = merge(tree[2*idx],tree[2*idx+1]);
}

node query(int idx ,int l ,int r ,int lq ,int rq){  // Query
    if(lq > r or l>rq){
        return node();
    }
    if(lq <= l && r <= rq){  // full overlap
        return tree[idx];    
    }
    int mid = (l+r)/2;
    return merge(query(2*idx,l,mid,lq,rq),query(2*idx+1,mid+1,r,lq,rq)) ;
}

/* write core logic here */
void solve(){
    int n,q;
    cin>>n>>q;
    arr.resize(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    build(1,0,n-1);  // ✅ must build before queries

    while(q--){
        int ch;
        cin>>ch;
        if(ch==1){
            int k,u;
            cin>>k>>u;
            k--;
            update(1,0,n-1,k,u);
        }
        else{
            int a,b;
            cin>>a>>b;
            a--,b--;
            node ans = query(1,0,n-1,a,b);
            cout<<ans.sum<<endl;
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
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}
