#include<bits/stdc++.h>
#include <cstdint>
using namespace std;
//using uint64_t=long long;
uint64_t a[4];
uint64_t n,k,m;

uint64_t nmul(uint64_t x, uint64_t y){
 	x%=m;
 	y%=m;
 	uint64_t result=0;
 	while(y){
 		//result%=m;
 		if(y&1)result=((result%m)+x)%m;
 		x=(x + x)%m;
 		y>>=1;
 	}
 	return result%m;
}
// uint64_t nmul(uint64_t a,uint64_t n)
// {
//      uint64_t ret;
//      if(n==0)
//        return 0;
//      ret=nmul(a,n/2);
//      ret=(ret+ret)%m;
//      if(n%2)
//         ret=(ret+a)%m;
//      return ret;
// }

void mmul(uint64_t a[], uint64_t b[]){
	uint64_t x0=(nmul(a[0], b[0])%m + nmul(a[1], b[2])%m)%m;
	uint64_t x1=(nmul(a[0], b[1])%m + nmul(a[1], b[3])%m)%m;
	uint64_t x2=(nmul(a[2], b[0])%m + nmul(a[3], b[2])%m)%m;
	uint64_t x3=(nmul(a[2], b[1])%m + nmul(a[3], b[3])%m)%m;
	b[0]=x0%m;
	b[1]=x1%m;
	b[2]=x2%m;
	b[3]=x3%m;
}

uint64_t solve(uint64_t n, uint64_t k, uint64_t m){
	uint64_t p=n-1;
	uint64_t b[]={1,0,0,1};
	//cout<<b[0]<<' '<<b[1]<<' '<<b[2]<<' '<<b[3]<<'\n';
	while(p){
		if(p&1)  mmul(a,b);
		mmul(a,a);
		p>>=1;
	//cout<<b[0]<<' '<<b[1]<<' '<<b[2]<<' '<<b[3]<<'\n';
	}
	//cout<<b[0]<<' '<<b[1]<<' '<<b[2]<<' '<<b[3]<<'\n';
	return (nmul(((k-1)%m),(b[0]%m))%m + (b[1]%m))%m;
}
int main(){
	ios_base::sync_with_stdio(0);
	int y;cin>>y;
	for (int i=0; i<y; i++){
		cin>>n>>k>>m;
		if(n==1){
			cout<<(k)%m<<'\n';
			continue;
		}
		a[0]=a[1]=(k-1);
		a[2]=1;
		a[3]=0;
		cout<<solve(n,k,m)%m<<'\n';
	}
	return 0;
}
