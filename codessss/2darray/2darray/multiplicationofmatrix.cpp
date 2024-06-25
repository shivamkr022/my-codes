#include<iostream>
using namespace std;
int main(){
    int m;
    cout<<"enter the rows of 1st matrix  ";
    cin>>m;
    int n;
    cout<<"enter the columns of 1st matrix  ";
    cin>>n;

     int p;
    cout<<"enter the rows 2nd matrix  ";
    cin>>p;
    int q;
    cout<<"enter the columns 2nd matrix  ";
    cin>>q;

    if(n==p){  // condn for matrix multplication
        int arr[m][n];
        cout<<"enter elemnets of 1st matrix  ";
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){  // first matrix
                cin>>arr[i][j];
            }
        }
        int brr[p][q];
        cout<<"enter elemnets of 2nd matrix  ";
        for(int i=0;i<p;i++){
            for(int j=0;j<q;j++){   // 2nd matrix
                cin>>brr[i][j];
            }
        }
        int res[m][q];
        for(int i=0;i<m;i++){
            for(int j=0;j<q;j++){   // res matrix
                res[i][j]=0;

                for(int k=0;k<p;k++){
                    res[i][j]+=arr[i][k]*brr[k][j];  // condn for matrix multplication
                }
            }
        }cout<<endl;
        for(int i=0;i<m;i++){
            for(int j=0;j<q;j++){   // printing the result
             cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else if(n!=p){
        cout<<"not possible";
    }
}