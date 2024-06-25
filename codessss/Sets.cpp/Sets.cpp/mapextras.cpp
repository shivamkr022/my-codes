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
#include<map>
using namespace std;

int main(){
    int nums[] = {4,1,7,8,9};
    int n = sizeof(nums) / sizeof(nums[0]);
    vector<pair<int,int>>v;

    for (int i = 0; i < n; i++){
        v.push_back({nums[i],i});
    }
    for (int i = 0; i < n; i++){
        cout<<v[i].first<<" ";
    }
}