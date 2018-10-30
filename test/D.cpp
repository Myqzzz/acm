#include<iostream>

using namespace std;

int main(){
	int n,m;
	while(cin>>n>>m){
		int flag=(n&1),k=m;
		for(int i=1;i<n;i++){
			if(flag==(i&1)){
				cout<<1<<' ';
				k--;
			}else{	
				cout<<0<<' ';
			}
		}
		cout<<k<<endl;

	}
	return 0;
}
