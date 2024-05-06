#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int st[60001];

int findnum(int n){
	if(st[n])return st[n];
	int j;
	for (j = 244; j*j > n; j--);
	int l = 1e9;
	for (int k = j; k >=1; k--) {
		l=min(l,findnum(n- (k*k))+1);
	}
	st[n]=l;
	return st[n];
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 1; i < 245; i++) {
		st[i*i]=1;
	}
	int n;
	cin>>n;
	cout<<findnum(n);
	return 0;
}
