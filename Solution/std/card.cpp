#include <bits/stdc++.h>
#define LL long long
#define db double
#define l first
#define r second
#define mk(a, b) make_pair(a, b)
#define Hzy(o) freopen(o".in", "r", stdin), freopen(o".out", "w", stdout)
using namespace std;

int read() {
	int w = 0, f = 0; char c = getchar();
	while((c < '0' || c > '9') && c != '-') c = getchar();
	if(c == '-') f = 1, c = getchar();
	while(c >= '0' && c <= '9') w = w * 10 + c - '0', c = getchar();
	return f ? -w : w;
}

int main() {
	int t = read();
	while(t--) {
		LL a, b, c;
		a = read(), b = read(), c = read();
		if(a % 3 || b % 3 || c % 3 ) {
			puts("NO");
			continue;
		}
		a /= 3, b /= 3, c /= 3;
		if(a + b + c != 0) {
			puts("NO");
			continue;
		}
		if(abs(a - b) % 3 || abs(b - c) % 3 || abs(a - c) % 3) {
			puts("NO");
			continue;
		}
			
		puts("YES");
	}
			
	return 0;
}
