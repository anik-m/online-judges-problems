#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ii=pair<int,int>;

bool taken[101];
priority_queue<ii>pq;
int arr[101][101];

void process(int vtx,int n){
	taken[vtx]=true;
	for (int i = 1; i <= n; i++) {
		if(i==vtx)continue;
		ii p = make_pair(-arr[vtx][i],-i);
		if(taken[i]==false)pq.push(p);
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int k,n;
	cin>>n>>k;
	int a[k+1];
	for (int i = 1; i <= k; i++) {
		cin>>a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin>>arr[i][j];
		}
	}
	for (int i = 1; i <= k; i++) {
		process(a[i],n);
	}
	int mincost=0;
	while(!pq.empty()){
		ii current = pq.top();
		pq.pop();
		if(!taken[-current.second]){
			mincost+=-current.first;
			process(-current.second,n);
		}
	}
	cout<<mincost;
	return 0;
}
