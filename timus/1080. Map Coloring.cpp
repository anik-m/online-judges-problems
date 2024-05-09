#include<bits/stdc++.h>
using namespace std;
using ll=long long;
bool wont = false;

void dfs(vector<vector<int>>& vii, vector<int>& vi, int ind, int prev){
	if(vi[ind] != -1){
		if(prev!=-1 && prev==vi[ind])wont=true;
	}
	else{
		//if(vii[ind].size()>2){
			//wont=true;
			//return;
		//}
		vi[ind]=(prev==0)?1:0;
		for(int neighbor: vii[ind]){
			dfs(vii,vi,neighbor,vi[ind]);
		}
	}
	return;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	vector<vector<int>> vii(n+1);
	for (int i = 1; i <= n; i++) {
		int u;
		while(cin>>u){
			if(!u)break;
			vii[i].push_back(u);
			vii[u].push_back(i);
		}
	}
	vector<int>vi(n+1,-1);
	for (int i = 1; i <= n; i++) {
		dfs(vii,vi,i,-1);
	}
	if(wont)cout<<-1;
	else{
		for (int i = 1; i <= n; i++) {
			cout<<vi[i];
		}
	}
	return 0;
}
