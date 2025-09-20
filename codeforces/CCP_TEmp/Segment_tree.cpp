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

// Building Segment Tree general template
/* 
  -------------------------
  Segment Tree Template
  Shivam 2.0
  -------------------------

  Steps to implement:
  1. Define a 'node' structure storing info for each segment (sum, min, max, etc.)
  2. Write a 'merge' function to combine two child nodes into parent node.
  3. Build tree recursively using 'build(idx, l, r)'.
  4. Write 'update(idx, l, r, pos, val)' for point updates.
  5. Write 'query(idx, l, r, lq, rq)' for range queries.
  6. Use tree array of size 4*N to safely store all nodes.
  7. Call 'build(1, 0, n-1)' after inputting array.
  8. Use 'update' & 'query' as needed in your solve() function.
*/

struct node{
    int sum;
    node(){
        sum = 0 ;
    }
};

node merge(node a ,node b){
    node ans ;
    ans.sum = a.sum + b.sum ;
    return ans ;
}

node tree[4*2000000]; // tree node ko array k form m store kar rhe hai

void build(int idx ,int l ,int r){ // left and right k bich tree bna rhe hai

    if(l==r){ // Leaf Node 
        tree[idx].sum = 0; // mark every value as 0 init
        return ;
    }
    int mid  = (l+r)/2;
    build(2*idx,l,mid);
    build(2*idx+1,mid+1,r);  // tree ban gya ab dono taraf se 
    // ab merge hoga 
    tree[idx] = merge(tree[2*idx], tree[2*idx+1]) ; 
}

void update (int idx ,int l ,int r , int pos , int val){ // position pe value ko update karna hai
    if(pos < l or pos > r){
        return ;
    }
    if(l==r){
        tree[idx].sum+=val ; //Only the leaf node actually stores the original array value and gets updated directly.
        return ;
    }
    int mid  = (l+r)/2;
    update(2*idx,l,mid,pos ,val);
    update(2*idx+1,mid+1,r,pos,val);  // tree ban gya ab dono taraf se 
    // ab update hoga 
    tree[idx] = merge(tree[2*idx], tree[2*idx+1]) ;  
}

node query(int idx ,int l ,int r ,int lq ,int rq){  // lq and lr are given query in ques 
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

    // INPUT;
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

