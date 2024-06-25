#include<iostream>
#include<map>
using namespace std;
int main(){
    map<string,int> m;   // creating map;

    m["shivam"]=2;
    m["raghav"]=66;    // easy insertion
    m["saurav"]=19;

    for(auto p:m){   // using for each loop
        cout<<p.first<<" "<<p.second<<endl;
    }

}