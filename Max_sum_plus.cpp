#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>


using namespace std;

const int maxn=1e6+100;
const int inf=0x7fffffff;
int a[maxn],pre[maxn],dp[maxn];

int main(){
	int n,m;
	while(cin>>n>>m){
		memset(dp,0,sizeof(dp));
		memset(pre,0,sizeof(pre));
		for(int i=1;i<=m;i++){
			cin>>a[i];
		}
		int ans;
		for(int i=1;i<=n;i++){
			ans=-inf;
			for(int j=i;j<=m;j++){
				dp[j]=max(dp[j-1],pre[j-1])+a[j];
				pre[j-1]=ans;
				ans=max(ans,dp[j]);
			}
			
		}
		cout<<ans<<endl;
				
	}
	return 0;
}
