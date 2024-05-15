#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int a[101][101];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin>>a[i][j];
		}
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			a[i][j]+=a[i-1][j];
		}
	}

	int sum=-100000;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			int s=0;
			for (int k = 1; k <= n; k++) {
				s=max(a[j][k]-a[i-1][k],s+a[j][k]-a[i-1][k]);
				sum=max(sum,s);
			}
		}
	}
	cout<<sum;
	return 0;
}
