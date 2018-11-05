#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

#define cio ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)

typedef long long ll;


const int maxn=40;


struct pt{

	int x,y,z;
}p[maxn*6];

int dp[maxn*6];

void deal(int a,int b,int c,int ct){
	p[ct].x=a;
	p[ct].y=b;
	p[ct].z=c;
}

bool cmp(pt a,pt b){
	if(a.x==b.x)
		return a.y<b.y;
	return a.x<b.x;
}

int main(){
	cio;
	int n,cnt=1;
	while(cin>>n&&n){
		int ct=0;
		for(int i=1;i<=n;i++){
			int x,y,z;
			cin>>x>>y>>z;
			deal(x,y,z,++ct);
			deal(x,z,y,++ct);
			deal(y,x,z,++ct);
			deal(y,z,x,++ct);
			deal(z,x,y,++ct);
			deal(z,y,x,++ct);
		}
		sort(p+1,p+ct+1,cmp);
		int ans=-1;

		for(int i=1;i<=ct;i++){
			dp[i]=p[i].z;
		}
		for(int i=1;i<=ct;i++){
			for(int j=i;j<=ct;j++){
				if(p[j].x>p[i].x&&p[j].y>p[i].y){
					dp[j]=max(dp[j],dp[i]+p[j].z);
				}
				ans=max(ans,dp[j]);
			}
			
		}
		cout<<"Case "<<cnt++<<": maximum height = "<<ans<<endl;
	}


	return 0;
}


