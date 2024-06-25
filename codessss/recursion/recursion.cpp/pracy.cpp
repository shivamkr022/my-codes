#include<iostream>
#include<vector>
using namespace std;
void subarray(int arr[],int idx,int n,vector<int>ans,int k){
    if(idx==n){
        if(ans.size()==k){
             for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<"";
          }
           cout<<endl;
        }
        return;
    }
    subarray(arr,idx+1,n,ans,k);
    ans.push_back(arr[idx]);
    subarray(arr,idx+1,n,ans,k);
}
int main(){
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int>v;
    int k=3;
    subarray(arr,0,n,v,k);

}