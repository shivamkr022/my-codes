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
void f(int arr[],int n,int idx,vector<int> ans){
    if(idx==n){
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        return;
    }
    f(arr,n,idx+1,ans);
    ans.push_back(arr[idx]);
    f(arr,n,idx+1,ans);
}

int main(){
    int arr[]={1,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int>v;
    f(arr,n,0,v);
}  