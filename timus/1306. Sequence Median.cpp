//#include<bits/stdc++.h>
#include<stdio.h>
#include<queue>
using namespace std;
using ll=long long;

int main(){
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	int n;
	scanf("%d",&n);
	priority_queue<unsigned int>pq;
	int mid=n/2+1,i;
	for (i = 0; i < mid && i<n; i++) {
		unsigned int u;
		scanf("%u",&u);
		pq.push(u);
		//cout<<'_'<<u<<'\n';
	}
	for (; i < n; i++) {
		unsigned int v;
		scanf("%u",&v);
		pq.push(v);
		pq.pop();
	}
	unsigned int y=pq.top();
	pq.pop();
	unsigned int z=pq.top();
	//cout<<(n%2)?y:(y+z);
	//cout<<y<<' '<<z<<' '<<(y*1.0+z*1.0)/2.0 <<'\n';
	if(n&1)printf("%.u.0",y);
	else printf("%.1f",(y*1.0+z*1.0)/2.0);//((y&1)?(y+z)/2+1:(y+z)/2));
	//else printf("%d.5",y/2+z/2);
	//else 
	//printf("%.1lf",((n%2)?y:((yz)%2?
	//cout<<'\n'<<printf("%.1f",1);
	return 0;

}
