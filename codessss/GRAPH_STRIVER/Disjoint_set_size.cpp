/*
  ----------------------------------------------------
 |                                                   |
 |      Code Crafted by Shivam - The Happy Coder     |
 |                                                   |
  ----------------------------------------------------
    \        ,     ,        /
      \      |     |      /
         \   \_/   /
           \  -----  /
             \_/

    Happy coding! May your bugs be few and your joy be infinite!

    -----------------------------------------
    🧠 WHAT THIS CODE DOES:
    -----------------------------------------
    🛠 We implemented Disjoint Set Union (DSU) using Union by Size.
    
    👣 Why DSU?
    -> Useful in Graphs to efficiently manage connected components.
       E.g., in Kruskal's Algorithm or to check cycle in undirected graphs.

    🔗 What are the steps we followed?
    1️⃣ Create a class `DisjointSet`:
        - It holds: parent[] → to store ultimate parent of each node.
                    size[]   → to track the size of each component/tree.

    2️⃣ Constructor: Initializes each node as its own parent.
                     Size of each component is 1 initially.

    3️⃣ `find_par(x)`: Finds the ultimate parent of x (with path compression).
    
    4️⃣ `UnionBySize(u, v)`: Connects two components.
         → Always attach smaller component under the larger one to keep depth low.
    
    🐾 Dog Analogy:
       Imagine each dog 🐶 starts as its own pack leader.
       Then, when two packs merge, the smaller pack joins the bigger one.
       `find_par` = ask dog who is your leader (with some barking recursion).
       `UnionBySize` = make a new larger pack when two groups meet at the dog park 🐕.

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

class DisjointSet {
    vector<int> size;     // stores size of component
    vector<int> parent;   // stores parent of node

public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;   // initially parent is self
            size[i] = 1;     // size of each component is 1
        }
    }
    // Path compression: flattens the tree
    int find_par(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = find_par(parent[node]); // path compressed
    }
    // Union by size: attach smaller tree under larger one
    void UnionBySize(int u, int v) {
        int ult_par_u = find_par(u);
        int ult_par_v = find_par(v);

        if (ult_par_u == ult_par_v) return; // already in same component

        // Attach smaller size tree under larger one
        if (size[ult_par_u] > size[ult_par_v]) {
            parent[ult_par_v] = ult_par_u;
            size[ult_par_u] += size[ult_par_v];
        }
        else {
            parent[ult_par_u] = ult_par_v;
            size[ult_par_v] += size[ult_par_u];
        }
    }
};

/* write core logic here */
void solve() {
    DisjointSet ds(7);  // create DSU for 1 to 7

    // Union operations (joining components)
    ds.UnionBySize(1, 2);
    ds.UnionBySize(2, 3);
    ds.UnionBySize(4, 5);
    ds.UnionBySize(6, 7);
    ds.UnionBySize(5, 7); // now 4,5,6,7 are connected

    // Check if 3 and 7 are in same component
    if (ds.find_par(3) == ds.find_par(7)) {
        cout << "same" << endl;
    } else {
        cout << "not same" << endl;
    }

    ds.UnionBySize(3, 7); // connect the two groups

    if (ds.find_par(3) == ds.find_par(7)) {
        cout << "same" << endl;
    } else {
        cout << "not same" << endl;
    }
}
/* logic ends */

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif
    int t;
    //cin >> t;
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
/*
    🐶 WOOF WOOF! Welcome to the doggo camp of DSU by size!

    Imagine each dog is part of a pack (i.e., a set). 
    Initially, every pupper is alone — a lone wolf! 🐺

    When two dog packs meet:
    - The SMALLER pack moves into the BIGGER pack’s camp.
    - Because... why move a big pack when the small one can wag their tails and join in easily?

    Why do we do this?
    🐾 To keep the barking chain (aka the tree) short!
    Less barking = faster answers = O(α(n)) time!

    🔄 Operations:
    - findParent(x): Follow the barking until you find the ALPHA 🐶 of the pack.
    - unionBySize(u, v): Let the smaller pack's alpha join the bigger one.
      (size[u_root] < size[v_root] ? swap them!)

    Remember:
    🔸 Packs like sticking with the bigger gang.
    🔸 No doggo likes a deep barking tree – too much work!
    🔸 Less barking = fast union-find magic.

    So next time you do DSU by size, imagine doggo diplomacy:
    "Hey small pack, join the big bark squad!" 🐶🐶🐶

    Woof woof, DSU complete! ✅
*/
