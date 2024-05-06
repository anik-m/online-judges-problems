#include <bits/stdc++.h> 
using namespace std;
using ll=long long;
using ui=unsigned int;
int main() {
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	int n;cin>>n;
	int a[n],d=0;//,e=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		d+=a[i];
	}
	int p=pow(2,n-1),w=d;
	for(int i=1;i<=p-1;i++){
		int l=0;
		for(int j=0;j<n;j++){
			if(i & (1<<j)){
				l+=a[j];
			}
		}
		d=min(d,abs(w-2*l));
	}
	cout<<d;
	return 0;
}

