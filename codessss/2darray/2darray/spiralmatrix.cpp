#include<iostream>
using namespace std;
int main(){
    int m;
    cout<<"enter the rows of 1st matrix  ";
    cin>>m;
    int n;
    cout<<"enter the columns of 1st matrix  ";
    cin>>n;
    int arr[m][n];
    cout<<"enter elemnets of 1st matrix  ";
    for(int i=0;i<m;i++){
     for(int j=0;j<n;j++){  // matrix creation
        cin>>arr[i][j];
    }
  }
  cout<<endl;
  // for spiral matrix
  int minr=0,maxr=m-1;
  int minc=0,maxc=n-1;
    while(minr<=maxr && minc<=maxc){  // right
        for(int j=minc;j<=maxc;j++){
            cout<<arr[minr][j]<<" ";  // we go left to right so row is same and col is varying
       }
       if(minr>maxr || minc>maxc)break;
       minr++;
       for(int i=minr;i<=maxr;i++){    // down
        cout<<arr[i][maxc]<<" ";     
       }                               // we go top to bottom so row is changing and col is constant 
       if(minr>maxr || minc>maxc)break;
       maxc--;
       for(int j=maxc;j>=minc;j--){    //left
        cout<<arr[maxr][j]<<" ";       // we go lft to right so row is fix and col is changing
       }
       if(minr>maxr || minc>maxc)break;
       maxr--;
       for(int i=maxr;i>=minr;i--){    // up
        cout<<arr[i][minc]<<" ";
       }
       minc++;
    }
}