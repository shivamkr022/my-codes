/*
  ------------------------------------------
 |                                        |
 |      Code Crafted by Shivam     |
 |                                        |
  ------------------------------------------
    \        ,     ,        /
      \      |     |      /
         \   \_/   /
           \  -----  /
             \_/
  
  Happy coding! 
*/

/* includes and all */
#include <bits/stdc++.h>
using namespace std;

void solve() {
   long long n,m;
   cin>>n>>m;
   long long a[n][m];
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>a[i][j];
    }
   }
if(n>1&&m==1){
    for(int i=0;i<n;i++){
        if(a[0][0]>a[1][0]){
            a[0][0]=a[1][0];
        }else if(i<n-1 && a[i][0]>a[i+1][0] && a[i][0]>a[i-1][0]){
            a[i][0]=max(a[i+1][0],a[i-1][0]);
        }else if(i==n-1&&a[i][0]>a[i-1][0]){
            a[i][0]=a[i-1][0];
        
        }
    }
}
else if(n==1&&m>1){
    for(int i=0;i<m;i++){
        if(a[0][0]>a[0][1]){
            a[0][0]=a[0][1];
        }else if(i<m-1&&a[0][i]>a[0][i+1]&&a[0][i]>a[0][i-1]){
            a[0][i]=max(a[0][i+1],a[0][i-1]);
        }else if(i==m-1&&a[0][i]>a[0][i-1]){
            a[0][i]=a[0][i-1];
        
        }
    }
}else{     
   for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        if(i==0&&j==0){
            if(a[i][j]>a[i+1][j]&&a[i][j]>a[i][j+1]){
                a[i][j]=max(a[i+1][j],a[i][j+1]);          
                  }
        }else if(i==0&&j==m-1){
            if(a[i][j]>a[i+1][j]&&a[i][j]>a[i][j-1]){
                a[i][j]=max(a[i+1][j],a[i][j-1]); }
        }else if(i==n-1&&j==0){
               if(a[i][j]>a[i-1][j]&&a[i][j]>a[i][j+1]){
                a[i][j]=max(a[i-1][j],a[i][j+1]);          
                  }
        }else if(i==n-1&&j==m-1){
             if(a[i][j]>a[i-1][j]&&a[i][j]>a[i][j-1]){
                a[i][j]=max(a[i-1][j],a[i][j-1]);          
                  }
        }else if(i==0){
            if(a[i][j]>a[i+1][j]&&a[i][j]>a[i][j+1]&&a[i][j]>a[i][j-1]){
                a[i][j]=max(a[i+1][j],max(a[i][j-1],a[i][j+1]));          
                  }
        }else if(i==n-1){
            if(a[i][j]>a[i-1][j]&&a[i][j]>a[i][j+1]&&a[i][j]>a[i][j-1]){
                a[i][j]=max(a[i-1][j],max(a[i][j-1],a[i][j+1]));          
                  }
        }else if(j==0){
            if(a[i][j]>a[i+1][j]&&a[i][j]>a[i][j+1]&&a[i][j]>a[i-1][j]){
                a[i][j]=max(a[i+1][j],max(a[i-1][j],a[i][j+1]));          
                  }
        }else if(j==m-1){
            if(a[i][j]>a[i+1][j]&&a[i][j]>a[i][j-1]&&a[i][j]>a[i-1][j]){
                a[i][j]=max(a[i+1][j],max(a[i-1][j],a[i][j-1]));          
                  }
        }
        else if(a[i][j]>a[i+1][j]&&a[i][j]>a[i][j+1]&&a[i][j]>a[i][j-1]&&a[i][j]>a[i-1][j]){
                a[i][j]=max(max(a[i+1][j],a[i-1][j]),max(a[i][j+1],a[i][j-1]));
        }
      }
   }}

   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cout<<a[i][j]<<" ";
    }cout<<endl;
   }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}