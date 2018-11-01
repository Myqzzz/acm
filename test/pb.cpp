#include<iostream>
#include<algorithm>

using namespace std;


const int maxn= 1e5+10;
int a[maxn],l[maxn],r[maxn];

int main(){
	int n;
	while(cin>>n){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int sum=-1001,sun=-1001;
		for(int i=1;i<=n;i++){
			sum=sum>0?(sum+a[i]):a[i];
			sun=max(sun,sum);	
			l[i]=sun;
		
		}
		sum=sun=-1001;
		for(int i=n;i>=1;i--){
			sum=sum>0?(sum+a[i]):a[i];
			sun=max(sun,sum);
			r[i]=sun;
		}
		int mx=-1e9;
		for(int i=2;i<=n;i++){
			mx=max(mx,l[i-1]+r[i]);
		}
		if(mx<0)
			cout<<0<<endl;
		else
			cout<<mx<<endl;


			
	}
	
	return 0;
}

