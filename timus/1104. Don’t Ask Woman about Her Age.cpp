#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	getline(cin,s);
	//bool sol = false;
	for(int j=2;j<37;j++){
		//long long mulf = 1;
		long long num=0;
		for(int i=(int)s.size()-1;i>=0;i--){
			int dig=50;
			if(s[i]>='0' && s[i]<='9')
				dig = s[i]-'0';
			else if(s[i]>='A' && s[i]<='Z')
				dig = s[i]-'A'+10;
			else continue;
			//if(dig>=j)break;
			//if(dig<j){
				//num+=(dig*mulf)%(j-1);
				//mulf *= j;
				//mulf%=(j-1);
			//} else {
			if(dig>=j){
				num=-1;
				break;
			}
			num+=dig;
		}
		if(num==-1)continue;
		else if( !(num%(j-1))){
			cout<<j;
			return 0;
		}
	}
	//if(!sol)
	cout<<"No solution.";

	return 0;
}
