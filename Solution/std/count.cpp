#include <bits/stdc++.h>
#define LL long long
#define db double
#define l first
#define r second
#define mk(a, b) make_pair(a, b)
#define Hzy(o) freopen(o".in", "r", stdin), freopen(o".out", "w", stdout)
#define calc(a, b) ((a) * ((b) - (a)) * 2 + (a) * ((a) - 1))
using namespace std;
const int N = 1000010;

int read() {
	int w = 0, f = 0; char c = getchar();
	while((c < '0' || c > '9') && c != '-') c = getchar();
	if(c == '-') f = 1, c = getchar();
	while(c >= '0' && c <= '9') w = w * 10 + c - '0', c = getchar();
	return f ? -w : w;
}

LL n, m, ans = 0;

pair<LL, LL> a[N];

int main() {
	n = read(), m = read();
	for(int i = 1; i <= m; ++i)
		a[i].l = read(), a[i].r = -read();
	sort(a + 1, a + m + 1);
	for(int i = 1; i <= m; ++i)
		a[i].r = -a[i].r;
	int cnt = 1;
	for(int i = 2; i <= m; ++i)
		if(a[i].r > a[cnt].r)
			a[++cnt] = a[i];
	int p = 1;
	
	for(int i = 1; i <= cnt; ++i) {
		while(p < cnt && a[p + 1].l <= a[i].r)
			p++;
		LL len;
		if(i == cnt || a[i + 1].l >= a[i].r)
			len = a[i].r - a[i].l + 1;
		else
			len = a[i + 1].l - a[i].l;
		ans += calc(len, a[p].r - a[i].l + 1);
	}
	cout << ans << endl;					
				
	return 0;
}
