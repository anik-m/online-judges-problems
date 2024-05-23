#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int parent[100010],stature[100010],setn;
vector<pair<int,int>>v(100010);

int find_parent(int v){
	if(parent[v]==v)return v;
	return parent[v]=find_parent(parent[v]);
}
void unions(int x,int y){
	if(x==y)return;
	int px=find_parent(x),py=find_parent(y);
	if(px==py)return;
	setn--;
	if(stature[py]>stature[px])parent[px]=py;
	else{
		parent[py]=px;
		if(stature[px]==stature[py])stature[px]++;
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//memset(parent,-1,sizeof(parent));
	int n,m;
	cin>>n>>m;

	for (int i = 1; i <= n; i++) {
		parent[i]=i;
		stature[i]=0;
	}
	setn=n;//all elements are disjoint sets
	for (int i = 1; i <= m; i++) {
		int x,y;
		cin>>x>>y;
		v[i].first=x;
		v[i].second=y;
	}
	int q;
	cin>>q;
	bool qa[m+1];
	memset(qa,1,sizeof(qa));
	int query[q+1];
	for (int i = 1; i <= q; i++) {
		cin>>query[i];
		qa[query[i]]=0;
	}
	for (int i = 1; i <= m; i++) {
		if(qa[i])unions(v[i].first,v[i].second);
	}
	stack<int>st;
	for (int i = q; i >= 1; i--) {
		st.push(setn);
		unions(v[query[i]].first,v[query[i]].second);
	}
	//cout<<st.top();
	//st.pop();
	for (int i = 1; i <= q; i++) {
	//while(!st.empty()){
		cout<<st.top()<<' ';
		st.pop();
	}		
	//cout<<'\n';
	return 0;
}
