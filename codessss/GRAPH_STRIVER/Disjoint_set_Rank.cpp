
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

/*

🔍 WHY USE DISJOINT SET UNION (DSU)?
-------------------------------------
We use DSU when we need to:
- Track which elements belong to the same group.
- Efficiently merge groups.
- Quickly check if two elements are in the same set.

✨ Examples:
- Kruskal’s Algorithm (MST)
- Cycle Detection in Graphs
- Dynamic Connectivity

📦 DSU Terminology:
---------------------
- `parent[i]` → Represents the group leader (ultimate parent) of node `i`.
- `rank[i]`   → Helps us keep the tree shallow (optimization).

------------------------------------------------------
📌 STEPS TO WRITE DSU CLASS AND WHY THIS ORDER MATTERS:
------------------------------------------------------

✅ 1. `parent` & `rank` vectors (private)  
👉 These store the DSU structure. Private ensures only class manages them.

✅ 2. Constructor  
👉 Initializes every node as its own parent (each node starts in its own group).  
👉 Rank is set to 0.

✅ 3. `find_par(node)`  
👉 Finds the leader of a node’s group using path compression.  
👉 Path compression flattens the tree, making future queries fast.

✅ 4. `UnionByRank(u, v)`  
👉 Merges two groups.  
👉 Uses rank to ensure small tree is attached under big one.  
👉 If ranks are equal, choose one and increase its rank.

🧠 Why this sequence?
- First we need a structure (parent & rank),
- Then we need a way to find a node’s leader (find),
- Then a way to unite two sets (union).

------------------------------------------------------
🐶 DSU DOG PACK ANALOGY (WOOF WOOF):
------------------------------------------------------

Every dog 🐕 starts alone — it leads its own pack.  
When dogs 🐕🐶 meet, they form a bigger pack, and the stronger (rank-wise) becomes the **alpha** 🦴.

Over time, many dogs will bark 🐾 directly to their alpha 🐕‍🦺 using path compression.

     🐶      🐶      🐶
      |       |       |
    leader  leader  leader

After unions...

         🐶
        / | \
     🐶  🐶  🐶    <-- now they all follow one alpha!

Path compression makes them reach the alpha fast.  
This is how we optimize and keep DSU efficient.

🔒 Private variables:
Only the class knows how to manage the pack — we don’t let outsiders mess with `rank` or `parent` directly.
Let the alpha manage the pack 😎

---
Let’s go, alpha Shivam 🐾 — unite those doggos efficiently!
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

class DisjointSet{

    vector<int> rank , parent ;  // private by default in class
    // rank stores the depth (or height) of the tree rooted at a node.
    // During union, we attach the smaller tree to the bigger one, based on rank, to avoid deep trees

    public :

    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }

    int find_par(int node){
        if(node == parent[node]){
            return node ;  // we got ultimate parent
        }
        return parent[node] = find_par(parent[node]) ; // By recursion we get ultimate parent of Node
    }

    void UnionByRank(int u , int v){
        int ult_par_u = find_par(u);
        int ult_par_v = find_par(v);
        if(ult_par_u == ult_par_v) return ; // connected by same ult parent

        // rank only inc when rank of both ult par same 
        // then only rank inc 
        // else just connection happens;
        // higher rank will became parent

        if(rank[ult_par_u] > rank[ult_par_v]){
            parent[ult_par_v] = ult_par_u ;
        }
        else if (rank[ult_par_v] > rank[ult_par_u]){
            parent[ult_par_v] = ult_par_u;
        }
        else if(rank[ult_par_v] == rank[ult_par_u]){
            parent[ult_par_u] = ult_par_v; // par of ult_par_u ban jayega ult_par_v
            rank[ult_par_v]++; // rank will innc as level inc here
        }
    }

};

/* write core logic here */
void solve(){
    DisjointSet ds(7);
    ds.UnionByRank(1,2);
    ds.UnionByRank(2,3);
    ds.UnionByRank(4,5);
    ds.UnionByRank(6,7);
    ds.UnionByRank(5,7);

    if(ds.find_par(3) == ds.find_par(7)){
        cout<<" same" <<endl;
    }
    else{
        cout<<"not same " << endl;
    }

    ds.UnionByRank(3,7);

        if(ds.find_par(3) == ds.find_par(7)){
        cout<<" same"<<endl;
    }
    else{
        cout<<"not same " << endl;
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

