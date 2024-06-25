#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    unordered_map<string,int> m;   // creating map;

    pair<string,int>p1;  // creating pair
    p1.first="shivam";   // give val 
    p1.second=2;

    pair<string,int>p2;   // bakwas insertion
    p2.first="lokesh";
    p2.second=17;

    m["raghav"]=66;    // easy insertion

    m.insert(p1);
    m.insert(p2);

    for(auto p:m){   // using for each loop
        cout<<p.first<<" "<<p.second<<endl;
    }
    cout<<endl;
    m.erase("lokesh");

        for(auto p:m){   // using for each loop
        cout<<p.first<<" "<<p.second<<endl;
    }
}