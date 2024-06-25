#include<iostream>
using namespace std;
int main(){
    int m;
    cout<<"enter the rows of  matrix  ";
    cin>>m;
    int n;
    cout<<"enter the columns of matrix  ";
    cin>>n;

        int arr[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){  // normal matrix input
                cin>>arr[i][j];
            }
        }
        cout<<endl;
        for(int i=0;i<m;i++){  // we have to reverse only odd row so we nothing do here
            if(i%2==0){
                for(int j=0;j<n;j++){  
                cout<<arr[i][j]<<" ";
              }
    
            }
            else{
                for(int j=n-1;j>=0;j--){  // we reverse the odd row
                    cout<<arr[i][j]<<" ";
                }
            }
            cout<<endl;
        }
}