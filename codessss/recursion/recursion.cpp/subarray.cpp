#include<iostream>
#include<vector>
using namespace std;
void sub(int arr[],int n,int idx,vector<int>ans){
    if(idx==n){
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        return;

    }
    sub(arr,n,idx+1,ans);
    ans.push_back(arr[idx]);
    sub(arr,n,idx+1,ans);
}
int main(){
    int arr[]={1,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int>v;
    sub(arr,n,0,v);

}