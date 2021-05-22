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

string s;

int main() {
	cin >> s;
	int state = 0;
	for(size_t i = 0; i < s.size(); ++i) {
		if(state == 0) {
			if(s[i] == 'o' || s[i] == 'O')
				state++;
			else
				state = -1;
		}
		else if(state == 1) {
			if(s[i] == 'g')
				state++;
			else if(s[i] == 'o' || s[i] == 'O')
				continue;
			else
				state = -1;
		}
		else if(state == 2) {
			if(s[i] == 'i')
				state++;
			else if(s[i] == 'g')
				continue;
			else
				state = -1;
		}
		else if(state == 3) {
			if(s[i] == 'i')
				continue;
			else
				state = -1;
		}
	}
	if(state == 3)
		puts("YES");
	else
		puts("NO");														 
	return 0;
}
