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

///n*logn 存疑

/*
4 2
5 2
5 1

4 1
4 2
5 2
5 1

1 8
2 7
3 6
4 8
5 4

---??
4 1
4 2
5 3
5 2
5 1

*/
/*
#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

#define cio ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)

typedef long long ll;


const int maxn=1e3+100;

int dp[maxn];

struct mouse{
	int w,v,l;
}p[maxn],d[maxn];

bool cmp(mouse a,mouse b){
	if(a.w==b.w)
		return a.v>b.v;
	return a.w<b.w;
}

void deal(mouse *a,mouse b){
	a->w=b.w,a->v=b.v,a->l=b.l;
}

int Next[maxn];

void print(int stp,int cnt){

	if(cnt>0){
	
		print(Next[stp],cnt-1);
		cout<<stp<<endl;
	}
}

int main(){
	cio;
	int t=0;
	while(++t,cin>>p[t].w>>p[t].v){
       	 p[t].l=t;
        }
	t--;
	sort(p+1,p+t+1,cmp);
	int ct=1,ed=1;
	for(int i=1;i<=t;i++){
		Next[i]=-1;
	}
	deal(&d[ct],p[1]);
	for(int i=2;i<=t;i++){
		if(p[i].w>d[ct].w){
			if(p[i].v<d[ct].v){
				ed=p[i].l;
				Next[p[i].l]=d[ct].l;
				ct++;
				deal(&d[ct],p[i]);
			}
			else{
				if(d[ct].v==p[i].v)continue;
				int l=1,r=ct;
				while(l<r){
					int mid=(r-l>>1)+l;
					if(d[mid].v>p[i].v){
						l=mid+1;
					}else{
						r=mid-1;
					}
				}
				Next[p[i].l]=Next[d[l].l];
				deal(&d[l],p[i]);
				
			}
		}
	}
	cout<<ct<<endl;
	print(ed,ct);
	return 0;
}*/
