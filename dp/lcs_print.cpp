//hdu 1160 lcs + 打印 


#include<iostream>
#include<cstring>
#include<algorithm>


using namespace std;

#define cio ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)

typedef long long ll;

const int maxn=1e3+111;
const int inf = 0x7fffffff;

struct ms{
	int m,v,n;
}a[maxn];

bool cmp(ms x,ms y){
	return x.m<y.m;
}

int dp[maxn],Next[maxn];

void Print(int stp,int cnt){
	if(cnt>0){
		Print(Next[stp],cnt-1);
		cout<<a[stp].n<<endl;
	}

}


int main(){
	cio;
	int ct=1;
	while(cin>>a[ct].m>>a[ct].v){
		a[ct].n=ct;
		ct++;
	}
	ct--;
	sort(a+1,a+ct+1,cmp);
	int md=1,ans=-1;
	for(int i=1;i<=ct;i++)Next[i]=-1,dp[i]=1;
	for(int i=1;i<=ct;i++){
		for(int j=i;j<=ct;j++){
			if(a[j].v<a[i].v&&a[j].m>a[i].m&&dp[j]<dp[i]+1){
				dp[j]=dp[i]+1;
				Next[j]=i;
			}
			if(ans<dp[j]){
				ans=dp[j],md=j;	
			}
		}
	}
	cout<<ans<<endl;
	Print(md,ans);
	return 0;
}
