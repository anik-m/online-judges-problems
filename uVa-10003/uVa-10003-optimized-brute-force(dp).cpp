#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int b[52][52];
int ans(int l,int r,int arr[]){
	if(l==r-1)b[l][r]=0;
	if(b[l][r]!=-1) return b[l][r];
	int y=1e9;
	for(int i=l+1;i<r;i++)y=min(y,ans(l,i,arr)+ans(i,r,arr)+arr[r]-arr[l]);
	b[l][r]=y;
	return b[l][r];
}
int main(){
	int l;
	while(cin>>l){
		if(!l)break;
		int n;cin>>n;
		int a[n+2];
		memset(b,-1,sizeof b);
		a[0]=0;
		a[n+1]=l;
		for(int i=1;i<=n;i++){
			int temp;cin>>temp;
			a[i]=temp;
		}
		printf("The minimum cutting is %d.\n",ans(0,n+1,a));
	}
	return 0;
}
