#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int a[15][15];

int fact(int n){
	if(n<=1) return 1;
	return n*fact(n-1);
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	a[1][1]=1;
	int n;
	for (int i = 2; i < 15; i++) {
		for (int j = 1; j <= i; j++) {
			a[i][j]=j*a[i-1][j]+a[i-1][j-1];
		}
	}
	while(cin>>n){
		if(n==-1)break;
		int y=0;
		for (int i = 0; i < n; i++) {
			int x=a[n][i+1]*fact(i+1);//(fact(n)/(fact(i+1)));//(fact(n)/(fact(n-i)*fact(i)));
			y+=x;
		}
		cout<<y<<'\n';
	}
	return 0;
}
