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
#include<queue>
#include<list>
using namespace std;

vector<list<int>> graph;  // vector of list
unordered_set<int>visited; // to store/mark visited vertices
int v;

void add_edge(int src ,int dest,bool bidrec=true){
  graph[src].push_back(dest); // if unidirectional graph is given
  
  if(bidrec){   // if graph is bidrectional
    graph[dest].push_back(src);
  }
}
void bfs(int src,int des ,vector<int>&dis){
    queue<int>q;
    visited.clear();
    dis.resize(v,INT_MAX);
    dis[src]=0;
    visited.insert(src);
    q.push(src);

    while(not q.empty()){
        int curr = q.front();
        q.pop();
        for(auto neighbour : graph[curr]){
            if(not visited.count(neighbour)){
                q.push(neighbour);
                visited.insert(neighbour);
                dis[neighbour]=dis[curr]+1;
            }
        }
    }
}

int main(){
    cin>>v;
    graph.resize(v,list<int>());
    int e;
    cin>>e;
    visited.clear();
    while(e--){
        int s,d;
        cin>>s>>d;
        add_edge(s,d);
    }

    int x,y;
    cin>>x>>y;
    vector<int>dis;
    bfs(x,y,dis);
    for(int i=0;i<dis.size();i++){
        cout<<dis[i]<<" ";
    }
}