#include <bits/stdc++.h>
#define LL long long
#define db double
#define mk(a, b) make_pair(a, b)
#define Hzy(o) freopen(o ".in", "r", stdin), freopen(o ".out", "w", stdout)
using namespace std;
const int N = 100010;

int read() {
    int w = 0, f = 0;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-')
        f = 1, c = getchar();
    while (c >= '0' && c <= '9') w = w * 10 + c - '0', c = getchar();
    return f ? -w : w;
}

struct Seg {
    int l, r;
    Seg() {}
    Seg(int _l, int _r) : l(_l), r(_r) {}
    bool operator<(const Seg& b) const {
        return (r - l) / 2 == (b.r - b.l) / 2 ? l > b.l : (r - l) / 2 < (b.r - b.l) / 2;
    }
    bool operator==(const Seg& b) const { return l == b.l && r == b.r; }
};

int n, k, q, a[N], Min, Max;
bool vis[N];

set<int> S;
priority_queue<Seg> Q;

void add_Seg(int l, int r) {
    if (l > r || l < 1 || r > n)
        return;
    Q.push(Seg(l, r));
}

bool check(Seg a) {
    set<int>::iterator it = S.lower_bound(a.r + 1);
    it--;
    if (*it != a.l - 1)
        return false;
    return true;
}

int main() {
    n = read(), k = read(), q = read();
    int op, tmp;
    set<int>::iterator it1, it2;
    Seg tp;
    for (int i = 1; i <= k; ++i) a[i] = read();
    sort(a + 1, a + k + 1);
    for (int i = 1; i <= k; ++i) {
        vis[a[i]] = 1;
        S.insert(a[i]);
    }
    S.insert(0), S.insert(n + 1);
    Min = a[1], Max = a[k];
    if (k == 0)
        Min = n + 1, Max = 0, Q.push(Seg(1, n));
    /*
        if(a[1] != 1)
                Q.push(Seg(-a[1] + 3, a[1] - 1));
        if(a[k] != n)
                Q.push(Seg(a[k] + 1, 2 * n - a[k]));
        */

    // S.insert(0), S.insert(n + 1);
    int l = 0;
    for (int i = 1; i <= n; ++i)
        if (!vis[i]) {
            if (!l)
                l = i;
        } else {
            if (l) {
                Q.push(Seg(l, i - 1));
                l = 0;
            }
        }
    if (l)
        Q.push(Seg(l, n));
    for (int i = 1; i <= q; ++i) {
        op = read();
        if (op == 1) {
            tmp = read();
            it1 = S.lower_bound(tmp);
            it2 = it1, it1--;
            add_Seg((*it1) + 1, tmp - 1), add_Seg(tmp + 1, (*it2) - 1);
            S.insert(tmp);
            vis[tmp] = 1;
            Min = min(Min, tmp), Max = max(Max, tmp);
        } else {
            while (!Q.empty()) {
                tp = Q.top(), Q.pop();
                if (!check(tp))
                    continue;
                Seg tp1(1, Min - 1), tp2(Max + 1, n);
                int dis = (tp.r - tp.l) / 2, dis_min = Min - 2, dis_max = n - Max - 1;
                if (vis[1])
                    dis_min = -1;
                if (vis[n])
                    dis_max = -1;
                if (dis_min >= dis && dis_min >= dis_max)
                    Q.push(tp), tp = tp1, dis = dis_min;
                if (dis_max > dis)
                    Q.push(tp), tp = tp2;
                if (tp == tp1) {
                    S.insert(1);
                    printf("%d\n", 1);
                    add_Seg(2, Min - 1);
                    vis[1] = 1;
                    Max = max(Max, 1);
                    break;
                }
                if (tp == tp2) {
                    S.insert(n);
                    printf("%d\n", n);
                    add_Seg(Max + 1, n - 1);
                    vis[n] = 1;
                    Min = min(Min, n);
                    break;
                }
                tmp = tp.l + (tp.r - tp.l) / 2;
                S.insert(tmp);
                printf("%d\n", tmp);
                add_Seg(tp.l, tmp - 1), add_Seg(tmp + 1, tp.r);
                vis[tmp] = 1;
                Min = min(Min, tmp), Max = max(Max, tmp);
                break;
            }
        }
    }
    return 0;
}
