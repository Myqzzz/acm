#include<iostream>
#include<cstring>
#include<algorithm>


using namespace std;

#define cio ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)

typedef long long ll;

const int maxn=1e6+111;
const int inf = 0x7fffffff;
int a[maxn],pre[maxn],dp[maxn];

int main(){
	cio;
	int n,m;
	while(cin>>n>>m){
		memset(pre,0,sizeof(pre));	
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int ans;
		for(int i=1;i<=m;i++){
			ans=-inf;
			for(int j=i;j<=n;j++){
				dp[j]=max(dp[j-1],pre[j-1])+a[j];
				pre[j-1]=ans;
				ans=max(ans,dp[j]);
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}


