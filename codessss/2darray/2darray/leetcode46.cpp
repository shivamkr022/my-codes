#include<iostream>
using namespace std;
int main(){
    int m;  // row 
    cout<<"enter the first number";
    cin>>m;
   
    int arr[m][m];
    for(int i=0;i<=m-1;i++){  // taking input for matrix 
        for(int j=0;j<=m-1;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<=m-1;i++){     // normal matrix printing
        for(int j=0;j<=m-1;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
     for(int i=0;i<=m-1;i++){   
        for(int j=i+1;j<=m-1;j++){
            swap(arr[i][j],arr[j][i]);
        }
        cout<<endl;
    }
    for(int k=0;k<=m;k++){ 
        int i=0;
        int j=m-1;
        while(i<=j){
        int temp=arr[k][i];
        arr[k][i]=arr[k][j];
        arr[k][j]=temp;
        i++;
        j--;
        }
        cout<<endl;

    }
     for(int i=0;i<=m-1;i++){     // rotate by 90 matrix printing
        for(int j=0;j<=m-1;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

 }
   