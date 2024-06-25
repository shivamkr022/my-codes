#include<iostream>
using namespace std;
int main(){
    int m;  // row 
    cout<<"enter the first number";
    cin>>m;
    int n;  // column
    cout<<"enter the second number";
    cin>>n;
    int arr[m][n];
    for(int i=0;i<=m-1;i++){  // taking input for matrix 
        for(int j=0;j<=n-1;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<=m-1;i++){     // normal matrix printing
        for(int j=0;j<=n-1;j++){
            cout<<arr[i][j]<<" ";
        }
            cout<<endl;
    }
    for(int j=0;j<=n-1;j++){
        for(int i=0;i<=m-1;i++){   // creating transpose
            cout<<arr[i][j]<<" ";
        }
            cout<<endl;
    }
}