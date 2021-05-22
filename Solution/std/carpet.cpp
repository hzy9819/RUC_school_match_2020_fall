#include <cstdio>
#include <cstring>
#include <algorithm>
#define ULL unsigned long long
#define Uint unsigned int
using namespace std;

int n,q;

ULL find(Uint x,int bs0)
{
	ULL res=((x&1ULL)^((x>>1)&1ULL))<<bs0;
	if(x&1ULL) return res;
	x>>=1;
	int bs=2+bs0;
	while(x)
	{
		res|=((x&1ULL)<<bs);
		x>>=1;
		bs+=2;
	}
	return res;
}

ULL getv(Uint x,Uint y)
{
	ULL bs=1ULL<<n,t;
	ULL res=0;
	while(bs)
	{
		t=bs>>1;
		if(x<t&&y>=t) res+=t*t,y-=t;
		else if(x>=t&&y<t) res+=t*t*2ULL,x-=t;
		else if(x>=t&&y>=t) res+=t*t*3ULL,x-=t,y-=t;
		bs>>=1;
	}
	return res;
}

int main()
{
	freopen("T2.in","r",stdin);
	freopen("T2.out","w",stdout);

	Uint x1,x2,y1,y2;
	ULL ans;
	int o1,o2;
	scanf("%d%d\n",&n,&q);
	for(int i=1;i<=q;++i)
	{
		scanf("%u%u%u%u\n",&x1,&y1,&x2,&y2);
		o1=(x2-x1+1)&1, o2=(y2-y1+1)&1;
		if(!o1&&!o2) ans=0;
		else if(!o1&&o2) ans=find(x2,1)^(x1?find(x1-1,1):0);
		else if(o1&&!o2) ans=find(y2,0)^(y1?find(y1-1,0):0);
		else ans=(x2?find(x2-1,1):0)^(x1?find(x1-1,1):0)^(y2?find(y2-1,0):0)^(y1?find(y1-1,0):0)^getv(x2,y2);
		printf("%llu\n",ans);
	}

	return 0;
}
