#include<iostream>
#include<stack>   
using namespace std;
int main(){
  
  int arr[]={3,1,2,5,4,6,2,3};
  int n= sizeof(arr)/sizeof(arr[0]);
  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  // now we do for next greater ele;
  int ans[n];
  stack<int> st;
  // we follow pop ,ans and push ;
  ans[0]=-1;
  st.push(arr[0]);  // assume it as base case 

  for(int i=1;i<=n;i++){
    while(st.size()>0 && st.top()<=arr[i]){  // so here we pop
    st.pop();
    }
    if(st.size()==0)ans[i]=-1;  // answer
    else ans[i]=st.top();  // agar top > arr[i] to ans me top push karo and then stack m wo arr[i] push karo
    st.push(arr[i]);     // push
  }
  for(int i=0;i<n;i++){
    cout<<ans[i]<<" ";
  }
}