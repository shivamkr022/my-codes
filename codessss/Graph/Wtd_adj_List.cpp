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

vector<list<pair<int,int>>> graph;  // vector of list
int v;

void add_edge(int src,int des,int wt,bool bidirn = true){
    graph[src].push_back({des,wt});
    if(bidirn){                     // if the graph is bidirectional
        graph[des].push_back({src,wt});
    }
}
// cout<<"("<<ele.first<<" "<<ele.second<<"), ";
void display(){
    for(int i=0;i<graph.size();i++){
    cout<<i<<"->";
    for(auto ele : graph[i]){
      cout<<"("<<ele.first<<" "<<ele.second<<"), ";   
    }
    cout<<"\n";
    }
}

int main(){
    cin>>v;
    graph.resize(v,list<pair<int,int>>());
    int e;
    cin>>e;
    while(e--){
        int s,d ,wt;
        cin>>s>>d>>wt;
        add_edge(s,d,wt);
    }
    display();
    return 0;
}