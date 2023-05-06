#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int process(int a[][4],int b[][4]){
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(a[i][j]){
				if((i==0 || i==3) && j>0 &&j<3){
					if(i==0){
						if(j==2)b[i+2][j+1]=a[i][j];
						if(j==1)b[i+1][j+2]=a[i][j];
					}
					if(i==3){
						if(j==2)b[i-1][j-2]=a[i][j];
						if(j==1)b[i-2][j-1]=a[i][j];
					}
				}
				else if((j==0 || j==3) && i>0 &&i<3){
					if(j==0){
						if(i==2)b[i-2][j+1]=a[i][j];
						if(i==1)b[i-1][j+2]=a[i][j];
					}
					if(j==3){
						if(i==2)b[i+1][j-2]=a[i][j];
						if(i==1)b[i+2][j-1]=a[i][j];
					}
				}
				else if(i==j)b[i][3-i]=a[i][j];
				else if((i==0 && j==3) || (i==3 && j==0))b[j][j]=a[i][j];
				else {
					if(i==2 &&j==1) b[i-1][j]=a[i][j];
					else if(i==1 && j==1)b[i][j+1]=a[i][j];
					else if(i==1 && j==2)b[i+1][j]=a[i][j];
					else if(i==2 && j==2)b[i][j-1]=a[i][j];
				}
			}
		}
	}
	return 0;
}

int main(){
	char c[4][4];
	int a[4][4];
	string s;
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			char temp;cin>>temp;
			a[i][j]=(temp=='X'?1:0);
		}
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			cin>>c[i][j];
			if(a[i][j])s+=c[i][j];
		}
	}
	//cout<<s<<'\n';
	int a2[4][4];
	memset(a2,0,sizeof a2);
	process(a,a2);
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(a2[i][j])s+=c[i][j];
		}
	}
	//cout<<s<<'\n';
	memset(a,0,sizeof a);
	process(a2,a);
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(a[i][j])s+=c[i][j];
		}
	}
	//cout<<s<<'\n';
	memset(a2,0,sizeof a2);
	process(a,a2);
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(a2[i][j])s+=c[i][j];
		}
	}
	cout<<s<<'\n';
	return 0;
}
