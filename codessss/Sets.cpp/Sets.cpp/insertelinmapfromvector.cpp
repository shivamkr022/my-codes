// /*
//   ------------------------------------------
//  |                                        |
//  |      Code Crafted by Shivam     |
//  |                                        |
//   ------------------------------------------
//     \        ,     ,        /
//       \      |     |      /
//          \   \_/   /
//            \  -----  /
//              \_/
  
//   Happy coding! 
// */

// /* includes and all */
// #include<iostream>
// #include<vector>
// #include<string>
// #include<algorithm>
// #include<climits>
// #include<unordered_map>
// #include<map>

// using namespace std;

// int main(){
// int nums[]={4,4};

// int n=sizeof(nums)/sizeof(nums[0]);
// unordered_map<int,int> mp;
        
// for(int i=0;i<n;i++)  //inserting each ele in map from given vector.
// mp[nums[i]]++ ;

//  for(auto x:mp){
//     cout<<x.first<<" ";
//   }
// }
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>
#include<unordered_map>
#include<map>

using namespace std;

int main() {
    int nums[] = {4,1,7,8,9};
    int n = sizeof(nums) / sizeof(nums[0]);
    map<int, int> mp;

    // Inserting each element into the map from the given array.
    for (int i = 0; i < n; i++)
        mp[nums[i]]++;
   sort(mp.begin(),mp.end());
    // Printing the elements of the map.
    for (auto x : mp)
        cout << x.first << " ";

    return 0;
}
