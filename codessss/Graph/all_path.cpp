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
vector<vector<int>>result;

void add_edge(int src ,int dest,bool bidrec=true){
  graph[src].push_back(dest); // if unidirectional graph is given
  
  if(bidrec){   // if graph is bidrectional
    graph[dest].push_back(src);
  }
}
void dfs(int curr ,int end,vector<int>&path){
    if(curr==end){
        path.push_back(curr);
        result.push_back(path);
        path.pop_back();
        return;
    }
   visited.insert(curr); // mark visited 
   path.push_back(curr);
    for(auto neighbour:graph[curr]){
        if(! visited.count(neighbour)){  // if its already visted then we got 1 and ! 1=0; and vice versa
            dfs(neighbour,end,path); 
        }
    }
    path.pop_back();
    visited.erase(curr);
    return;
}
void allpath(int src ,int dest){
    vector<int>v;
    return dfs(src,dest,v);
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
    allpath(x,y);
    for(auto path :result){
        for(auto ele:path){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    return 0;
}