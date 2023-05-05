#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	ll n,y;
	cin>>n;
	y=n;
	int count=0;
	while(y%2==0){
		count++;
		y/=2;
	}
	int sy=sqrt(y),i;
	for(i=3;i<=sy && i<=2e7;i+=2){
		if(count>20 || y==1)break;
		while(y%i==0){
			count++;
			y/=i;
		}
		sy=sqrt(y);
	}
	if(y!=1)++count;
	//cout<<count<<'\n';
	cout<<(count==20?"Yes":"No")<<'\n';

	return 0;
}
