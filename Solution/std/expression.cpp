#include <bits/stdc++.h>
#define LL long long
#define db double
#define Hzy(o) freopen(o ".in", "r", stdin), freopen(o ".out", "w", stdout)
using namespace std;
const int INF = 1 << 30;
const LL inf = 1LL << 60;
const int N = 1000010;
const LL weg = 998244353;
char s[N];
int n;
LL a[N], bin[N];
int read() {
    int w(0), f(0);
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-')
        f = 1, c = getchar();
    while (c >= '0' && c <= '9') w = w * 10 + c - '0', c = getchar();
    return f ? -w : w;
}
bool check(int d1, int d2) {
    int l1 = d1, l2 = d2 - d1, l3 = n - d2;
    if (max(l1, l2) > l3 || max(l1, l2) < l3 - 1 || d1 >= d2 || (s[1] == '0' && l1 != 1) ||
        (s[d1 + 1] == '0' && l2 != 1) || (s[d2 + 1] == '0' && l3 != 1))
        return false;
    LL x = a[d1], y = (a[d2] - a[d1] * bin[l2] % weg + weg) % weg,
       z = (a[n] - a[d2] * bin[l3] % weg + weg) % weg;
    return (x + y) % weg == z;
}
void print(int d1, int d2) {
    for (int i = 1; i <= n; ++i) {
        printf("%c", s[i]);
        if (i == d1)
            printf("+");
        if (i == d2)
            printf("=");
    }
    printf("\n");
}

int work() {
    scanf("%s", s + 1);
    bin[0] = 1;
    n = strlen(s + 1);
    for (int i = 1; i <= n; ++i) {
        bin[i] = (bin[i - 1] * 10) % weg;
        a[i] = (a[i - 1] * 10 + s[i] - '0') % weg;
    }
    int res;
    for (int i = 1; i <= (n / 2); ++i) {
        res = n - i;
        if (check(i, i + (res / 2))) {
            print(i, i + (res / 2));
            return 0;
        }
        if (check(i, i + (res / 2) - 1)) {
            print(i, i + (res / 2) - 1);
            return 0;
        }
        if (check(i, i + (res / 2) + 1)) {
            print(i, i + (res / 2) + 1);
            return 0;
        }
        if (check(i, i + (n - 2 * i))) {
            print(i, i + (n - 2 * i));
            return 0;
        }
        if (check(i, i + (n - 2 * i) - 1)) {
            print(i, i + (n - 2 * i) - 1);
            return 0;
        }
    }
    puts("-1");
    return 0;
}

int main() {
    // srand(time(0));
    int T;
    scanf("%d", &T);
    while (T--) {
        work();
    }

    return 0;
}
