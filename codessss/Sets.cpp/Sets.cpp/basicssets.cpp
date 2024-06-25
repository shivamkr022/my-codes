#include<iostream>
#include<unordered_set>
using namespace std;
int main(){
    unordered_set<int> s;   // creating set
    s.insert(1);
    s.insert(2);
    s.insert(3);     // giving value in set
    s.insert(4);
    s.insert(5);
    int tar = 44;

    if(s.find(tar)!=s.end()){  // a little diff concept 
        cout<<"exists"<<endl;
    }
    else cout<<"does not exists"<<endl;

    cout<<s.size()<<endl;   // print size

    s.erase(5);  // deletion

    cout<<s.size()<<endl;   // print size

    for(int ele : s){  // for each loop
        cout<<ele<<" ";   
    }
}