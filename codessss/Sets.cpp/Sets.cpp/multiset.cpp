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
#include<set>
using namespace std;

int main(){
multiset<int> s;
s.insert(4);
s.insert(5);
s.insert(3);
s.insert(1);
s.insert(2);

for(int x : s)
cout<< x <<" ";
}