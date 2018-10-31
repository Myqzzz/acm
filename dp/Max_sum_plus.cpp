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



/*
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>

using namespace std;

#define cio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)

typedef long long ll;

const int maxn=1e5+100;
ll dp[2][maxn][2];
int a[maxn];

int main() {
    //cio;
    int n,m;
    while(~scanf("%d",&n)) {
       	m=2;
	for(int i=1; i<=n; i++) {
            scanf("%d",&a[i]);
       	    dp[1][i][1]=dp[0][i][0]=dp[0][i][1]=dp[1][i][0]=0;
	}
        ll mx=-1e9;
        for(int i=1; i<=m; i++)
            for(int j=1; j<=n; j++) {
                dp[i&1][j][0]=max(dp[i&1][j-1][0],dp[i&1][j-1][1]);
                dp[i&1][j][1]=max(dp[i&1][j-1][1],max(dp[(i-1)&1][j-1][0],dp[(i-1)&1][j-1][1]))+a[j];
                if(i==m)
                    mx=max(max(dp[i&1][j][1],dp[i&1][j][0]),mx);
            }
        printf("%lld\n",mx<0?0:mx);
    }
    return 0;
}*/

