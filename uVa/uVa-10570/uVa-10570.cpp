//using cyclic sort-interesting idea
#include<bits/stdc++.h>
using namespace std;
int s[1003],t[1003],n;
int calc(int c[]){
	int temp=0;
	bool bin[n+1];
	memset(bin,0,sizeof bin);
	for(int k=1;k<=n;k++){
		if(!bin[k]){
			temp++;
			for(int j=k;!bin[j];j=c[j]){
				bin[j]=true;//bin array indicator for-keeping track of swap in the cyclic sort
			}
		}
	}
	return temp;
}
int main(){
	while(cin>>n){
		if(!n)break;
		for(int i=1;i<=n;i++){
			cin>>s[i];
			s[n+i]=t[n+1-i]=t[2*n+1-i]=s[i];
		}
		int power=0;
		for(int i=1;i<=n;i++){
			int b = max(calc(s+i),calc(t+i));
			power = max(power,b);
		}
		cout<<n-power<<'\n';
	}
	return 0;
}
