#include<iostream>
#include<set>   // ordered set
using namespace std;
int main(){
    set<int> s;   // creating set
    s.insert(3);
    s.insert(1);
    s.insert(5);     // giving value in set
    s.insert(2);
    s.insert(4);

    for(int ele : s){  // for each loop
        cout<<ele<<" ";   
    }
}