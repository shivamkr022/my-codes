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
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>
#include<unordered_set>
#include<list>
using namespace std;

vector<list<int>> graph;  // vector of list
int v;
unordered_set<int>visited; // to store/mark visited vertices

void add_edge(int src ,int dest,bool bidrec=true){
  graph[src].push_back(dest); // if unidirectional graph is given
  
  if(bidrec){   // if graph is bidrectional
    graph[dest].push_back(src);
  }
}
bool dfs(int curr ,int end){
    if(curr==end) return true; // base case
    visited.insert(curr); // mark visited 
    for(auto neighbour:graph[curr]){
        if(! visited.count(neighbour)){  // if its already visted then we got 1 and ! 1=0; and vice versa
            bool res = dfs(neighbour,end); 
            if(res) return true; 
        }
    }
    return false;
}
bool anypath(int src ,int dest){
    return dfs(src,dest);
}
int main(){
    cin>>v;
    graph.resize(v,list<int>());
    int e;
    cin>>e;
    while(e--){
        int s,d;
        cin>>s>>d;
        add_edge(s,d);
    }
    visited.clear();
    int x,y;
    cin>>x>>y;
    cout<<anypath(x,y)<<endl;
    return 0;
}