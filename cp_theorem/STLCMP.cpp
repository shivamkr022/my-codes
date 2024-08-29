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
using namespace std;

int main(){
    vector<int>arr;
    arr.push_back(3);
    arr.push_back(2);
    arr.push_back(5);
    arr.push_back(1);
    arr.push_back(4);

   
    sort(arr.begin(),arr.end(),greater<int>());
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}