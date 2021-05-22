#include <bits/stdc++.h>
#define LL long long
#define db double
#define l first
#define r second
#define mk(a, b) make_pair(a, b)
#define Hzy(o) freopen(o".in", "r", stdin), freopen(o".out", "w", stdout)
using namespace std;
const int N = 100010;

int n, a[N];
LL s[N], f[N][2];

int read() {
	int w = 0, f = 0; char c = getchar();
	while((c < '0' || c > '9') && c != '-') c = getchar();
	if(c == '-') f = 1, c = getchar();
	while(c >= '0' && c <= '9') w = w * 10 + c - '0', c = getchar();
	return f ? -w : w;
}

int main() {
	n = read();
	for(int i = 1; i <= n; ++i)
		a[i] = read(), s[i] = s[i - 1] + a[i];
	LL max1 = -s[n], max2 = s[n];
	for(int i = n - 1; i >= 2; --i) {
		LL tmp1 = max1, tmp2 = max2;
		tmp2 = max(max2, max1 + s[i]);
		tmp1 = max(max1, max2 - s[i]);
		max1 = tmp1, max2 = tmp2;
	}
	cout << max2 << endl;
	
	return 0;
}
