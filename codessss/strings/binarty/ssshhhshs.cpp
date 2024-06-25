#include<iostream>
using namespace std;
int main(){
    int arr[9]={18,2,5,9,15,17,1,21,24};
    int n=9;
    int ans=INT16_MAX;
    for(int i=0;i<n;i++){
        if(ans>arr[i]){
            ans=arr[i];
        }
    }
  cout<<ans<<endl;

}
