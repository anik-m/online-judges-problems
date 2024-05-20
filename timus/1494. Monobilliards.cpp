#include<bits/stdc++.h>
using namespace std;
using ll=long long;

bool arr[100001];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	int y;
	cin>>y;
	arr[y]=true;
	int mx=y;
	vector<int> un(n);
	int vtx=0;
	un[vtx]=((y==1)?2:y-1);
	for (int i = 1; i < n ; i++) {
		cin>>y;
		if(y>mx){
			arr[y]=true;
			if(y>mx+1 && !arr[y-1]){
				vtx++;
				un[vtx]=y-1;
			}
			mx=y;
		}
		else {//it has to be next smallest value from mx that has yet to come out
			if(y!=un[vtx]){
				//cout<<vtx<<' '<<un[vtx]<<'\n';
				cout<<"Cheater";
				return 0;
			}
			arr[un[vtx]]=true;
			if(arr[un[vtx]-1])vtx--;
			else{
				un[vtx]=un[vtx]-1;
			}
		}	
		//arr[mx]=true;
	}
	cout<<"Not a proof";
	return 0;
}
