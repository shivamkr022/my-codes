#include<bits/stdc++.h>
using namespace std;
int a[100000],x[100000];
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int T,n,q,i,j,mx;
	for(cin>>T;T>0;T--){
		cin>>n>>q;
		for(i=0;i<n;i++)cin>>a[i];
		for(i=0;i<q;i++)cin>>x[i];
		mx=100;
		for(j=0;j<q;j++){
			if(x[j]>=mx)continue;
			mx=x[j];
			for(i=0;i<n;i++){
				if(a[i]%(1<<(x[j]))==0)a[i]+=(1<<(x[j]-1));
			}
		}
		for(i=0;i<n;i++)cout<<a[i]<<' ';
		cout<<'\n';
	}
	return 0;
}