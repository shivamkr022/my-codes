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
int nums[]={1,4,4,2,4,5,7,7,3};
int n=sizeof(nums)/sizeof(nums[0]);
unordered_map<int,int> mp;
for(auto x:nums){
    mp[x]++;
}
for(auto y:mp){
    cout<<y.first<<" "<<y.second<<endl;
  }
}