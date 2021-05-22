#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <time.h>
#define LL long long
#define Hzy(o) freopen(o ".in", "r", stdin), freopen(o ".out", "w", stdout)
using namespace std;
clock_t begin;
const int weg = 9819;
const int hs_weg = (1 << 10);
const int N = (1e+6);
int gcd(int a, int b) {
    int c;
    if (a < b)
        swap(a, b);
    while (b) {
        c = a % b;
        a = b, b = c;
    }
    return a;
}
struct Hash_Line {
    int d, list[hs_weg], next[N];
    int St[N], Ans[N], G[N];
    inline void clear() {
        d = 0;
        memset(list, -1, sizeof list);
    }
    inline void Push(int st, int ans, int GCD) {
        int tmp = st & (hs_weg - 1);
        for (int i = list[tmp]; i >= 0; i = next[i])
            if (St[i] == st && G[i] == GCD) {
                Ans[i] = (Ans[i] + ans) % weg;
                return;
            }
        St[d] = st, Ans[d] = ans, G[d] = GCD, next[d] = list[tmp], list[tmp] = d++;
    }
} hs[2];
inline int read() {
    register int w(0);
    register char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') w = w * 10 + c - '0', c = getchar();
    return w;
}
int n, m, cur;
int a[1000010][21], p[1010][1010];
int ans, answ;
inline void Init() {
    n = read(), m = read();
    if (n < m) {
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j) a[j][i] = read();
        swap(n, m);
    } else {
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j) a[i][j] = read();
    }
    cur = 0;
    hs[0].clear(), hs[1].clear();
}
int c[21], cc[21], ch[8];
inline bool check(int *c) {
    for (int i = 1; i <= m; ++i)
        if (c[i] == 1)
            return true;
    return false;
}
inline int Conc(int *c) {
    register int res(0), now(2);
    memset(ch, 0, 32);
    ch[1] = 1;
    for (int i = 1; i <= m; ++i) {
        if (c[i] != 0 && !ch[c[i]])
            ch[c[i]] = now++;
        res <<= 3, res += ch[c[i]];
    }
    return res;
}
inline void Trans(int *c, int st) {
    for (int i = m; i >= 1; --i) c[i] = st & 7, st >>= 3;
}
// inline void LM(int *c) {
//	for(int i = m; i >= 1; --i) c[i] = c[i - 1];
//	c[0] = 0;
//}
inline void Copy(int *cc, int *c) {
    for (int i = 1; i <= m; ++i) c[i] = cc[i];
}
inline void Dp(int x, int y) {
    register int t1, t2, t;
    if (x == 1 && y == 1) {
        memset(c, 0, 4 * (m + 1));
        c[1] = 1;
        hs[cur].Push(Conc(c), 1, a[1][1]);
        return;
    }
    for (int i = 0; i < hs[cur ^ 1].d; ++i) {
        Trans(cc, hs[cur ^ 1].St[i]), cc[0] = 0;
        Copy(cc, c);
        c[0] = 0;
        t = c[y];
        t1 = 0;
        for (int j = 1; j <= m; ++j)
            if (j != y && c[j] == t) {
                t1 = 1;
                break;
            }
        c[y] = 0;
        if (t == 0)
            t1 = 1;
        // if(y == m) LM(c);
        if (t1 && check(c))
            hs[cur].Push(Conc(c), hs[cur ^ 1].Ans[i], hs[cur ^ 1].G[i]);
        if (a[x][y]) {
            Copy(cc, c);
            c[0] = 0;
            if (!c[y - 1] && !c[y]) {
                c[y] = 7;
                // if(y == m) LM(c);
                hs[cur].Push(Conc(c), hs[cur ^ 1].Ans[i], p[hs[cur ^ 1].G[i]][a[x][y]]);
            } else if (!c[y - 1] && c[y]) {
                // c[y - 1] = c[y];
                // if(y == m) LM(c);
                hs[cur].Push(Conc(c), hs[cur ^ 1].Ans[i], p[hs[cur ^ 1].G[i]][a[x][y]]);
            } else if (c[y - 1] && !c[y]) {
                // if(y == m) LM(c);
                c[y] = c[y - 1];
                hs[cur].Push(Conc(c), hs[cur ^ 1].Ans[i], p[hs[cur ^ 1].G[i]][a[x][y]]);
            } else if (c[y] && c[y - 1]) {
                if (c[y] != c[y - 1]) {
                    t1 = c[y], t2 = c[y - 1], t = min(t1, t2);
                    for (int j = 1; j <= m; ++j)
                        if (c[j] == t1 || c[j] == t2)
                            c[j] = t;
                }
                // if(y == m) LM(c);
                hs[cur].Push(Conc(c), hs[cur ^ 1].Ans[i], p[hs[cur ^ 1].G[i]][a[x][y]]);
            }
        }
    }
}
inline void work() {
    if (a[1][1] == 0 || a[n][m] == 0) {
        answ = ans = 0;
        return;
    }
    int i, j;
    for (i = 1; i <= n; ++i)
        for (j = 1; j <= m; ++j) {
            cur ^= 1;
            hs[cur].clear();
            Dp(i, j);
        }
    ans = answ = 0;
    bool flag;
    for (i = 0; i < hs[cur].d; ++i) {
        Trans(c, hs[cur].St[i]);
        flag = 0;
        for (int j = 1; j <= m; ++j)
            if (c[j] && c[j] != 1) {
                flag = 1;
                break;
            }
        if (flag)
            continue;
        if (c[m] == 1 && answ < hs[cur].G[i]) {
            // Mod(ans, hs[cur].Ans[i]);
            answ = hs[cur].G[i], ans = hs[cur].Ans[i];
        } else if (c[m] == 1 && answ == hs[cur].G[i])
            ans = (ans + hs[cur].Ans[i]) % weg;
    }
}
void prep() {
    for (int i = 1; i <= 1000; ++i)
        for (int j = i; j <= 1000; ++j) p[i][j] = gcd(i, j), p[j][i] = p[i][j];
}
int main() {
    int t;
    prep();
    t = read();
    while (t--) {
        Init();
        work();
        cout << answ << " " << ans << endl;
    }
    // cout << sizeof a + sizeof hs << endl;
    // cout << clock() - begin << endl;
    return 0;
}
