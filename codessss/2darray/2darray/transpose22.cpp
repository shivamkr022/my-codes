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
    int transpose[n][m];
    for(int i=0;i<=n-1;i++){  // taking input for transpose  matrix 
        for(int j=0;j<=m-1;j++){
            transpose[i][j]=arr[j][i];
        }
        cout<<endl;
    }
     for(int i=0;i<=n-1;i++){   // 
        for(int j=0;j<=m-1;j++){  // printing the transpose
            cout<<transpose[i][j];
        }
        cout<<endl;
    }
 }
   