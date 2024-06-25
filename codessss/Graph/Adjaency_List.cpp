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
#include<list>
using namespace std;

vector<list<int>> graph;  // vector of list
int v;

void add_edge(int src ,int dest,bool bidrec=true){
  graph[src].push_back(dest); // if unidirectional graph is given
  
  if(bidrec){   // if graph is bidrectional
    graph[dest].push_back(src);
  }
}

void display(){
    for(int i=0;i<graph.size();i++){
    cout<<i<<"->";
    for(int ele : graph[i]){
        cout<<ele<<",";
    }
    cout<<"\n";
    }
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
    display();
    return 0;
}