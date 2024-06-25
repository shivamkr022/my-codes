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
#include<unordered_map>
#include<map>

using namespace std;

int main(){
int nums[]={4,4,6,7,8,9};
unordered_map<int,bool> mp;
        
for(auto y :nums)  // Mark every elem presence in map.
 mp[y] = true;

 for(auto x:mp){
    cout<<x.first<<endl;
  }
}