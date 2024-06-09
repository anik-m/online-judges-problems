#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n;
int indx1=-2,indx2=-2,sel1=-2;
int indy1=-2,indy2=-2,sel2=-2;
void calc(int arr[],vector<int>& v,bool id){
	for(auto p:v){
		for(auto q:v){
			swap(arr[p],arr[q]);
			int x=0;
			for (int i = 1; i <= n; i++) {
				if(arr[i]>arr[i+1]){
					x++;
				}
			}
			swap(arr[p],arr[q]);
			if(!x){
				if(id){
					indx1=p;
					indx2=q;
					sel1 =1;
				}else{
					indy1 = n-q+1;
					indy2 = n-p+1;
					sel2 =1;
				}
				return;
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	int a[n+2],b[n+2];
	a[0]=b[0]=0;
	a[n+1]=b[n+1]=1e9+7;
	int y=0,x=0;
	vector<int>vx,vy;
	for (int i  = 1; i <= n ; i++) {
		cin>>a[i];
		b[n-i+1]=a[i];
	}
	for (int i = 1; i <= n-1; i++) {
		if(a[i]>a[i+1]){
			x++;
			int j;
			for (j = i; a[j-1] == a[i] ; j--);
			vx.push_back(j);
			for (j = i+1; a[j+1] == a[i+1] ; j++);
			vx.push_back(j);
		}if(b[i]>b[i+1]){
			y++;
			int j;
			for (j = i; b[j-1] == b[i] ; j--);
			vy.push_back(j);
			for (j = i+1; b[j+1] == b[i+1] ; j++);
			vy.push_back(j);
		}
	}
	if(!x || !y)cout<<"Nothing to do here";
	else{
		if(x<=2)calc(a,vx,true);
		if(y<=2)calc(b,vy,false);
		if(sel1==-2 && sel2==-2)cout<<"No hope";
		else{
			cout<<"Yes\n";
			if(sel1==1)cout<<min(indx1,indx2)<<' '<<max(indx1,indx2);
			else cout<<min(indy1,indy2)<<' '<<max(indy1,indy2);
		}
	}
	return 0;
}
