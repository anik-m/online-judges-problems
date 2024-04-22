#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	double l,r;
	cin>>l>>r;
	double area_circle=3.1415926535897932384*r*r;
	double h = r - l/2;
	if(h<=0)cout<<fixed<<setprecision(3)<<area_circle;
	else if((l*l) <= 2*r*r)cout<<fixed<<setprecision(3)<<l*l;
	else cout<<fixed<<setprecision(3)<<area_circle-(4*(r*r*acos(1- h/r) -(r-h)*sqrt(r*r - (r-h)*(r-h))));
	return 0;
}
