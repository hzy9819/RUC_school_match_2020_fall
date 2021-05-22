#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

const int MAXN = 200010;

struct Node {
    long long cover;
    long long max_h;
};

Node node[MAXN * 4];
long long sum_w[MAXN], w[MAXN], K;
int n, q;

int lowbit(int x) { return x & (-x); }

void sum_update(int x, const long long &d) {
    while (x <= n) {
        sum_w[x] += d;
        x += lowbit(x);
    }
}

long long sum_query(int x) {
    long long s = 0LL;

    while (x > 0) {
        s += sum_w[x];
        x -= lowbit(x);
    }

    return s;
}

void node_init(int k, int l, int r) {
    node[k].cover = 0LL;

    if (l == r) {
        node[k].max_h = K * l + sum_query(n) - sum_query(l);
        return;
    }

    int mid = (l + r) / 2;

    node_init(k * 2, l, mid);
    node_init(k * 2 + 1, mid + 1, r);

    node[k].max_h = max(node[k * 2].max_h, node[k * 2 + 1].max_h);
}

void node_update(int k, int l, int r, const int &ul, const int &ur, const long long &d) {
    //	printf("%d, %d, %lld\n",l,r,d);
    if (ul <= l && ur >= r) {
        node[k].cover += d;
        //		printf("end: %d, %d, %lld %lld\n", l, r, node[k].max_h, node[k].cover);
        return;
    }

    int mid = (l + r) / 2;

    node[k * 2].cover += node[k].cover;
    node[k * 2 + 1].cover += node[k].cover;
    node[k].cover = 0LL;

    if (ul <= mid)
        node_update(k * 2, l, mid, ul, ur, d);
    if (ur > mid)
        node_update(k * 2 + 1, mid + 1, r, ul, ur, d);

    node[k].max_h = max(node[k * 2].max_h + node[k * 2].cover, node[k * 2 + 1].max_h + node[k * 2 + 1].cover);
    //	printf("%d, %d maxh = %lld\n",l,r,node[k].max_h);
}

long long node_query(int k, int l, int r, const int &ql, const int &qr) {
    // printf("%d, %d,%lld,%lld\n",l,r,node[k].max_h,node[k].cover);
    if (ql <= l && qr >= r) {
        //	printf("ret %d, %d %lld %lld\n", l, r, node[k].max_h, node[k].cover);
        return node[k].max_h + node[k].cover;
    }

    int mid = (l + r) / 2;

    bool flag = false;
    long long maxi = 0LL;

    if (ql <= mid) {
        maxi = node_query(k * 2, l, mid, ql, qr);
        flag = true;
    }
    if (qr > mid) {
        if (flag)
            maxi = max(maxi, node_query(k * 2 + 1, mid + 1, r, ql, qr));
        else
            maxi = node_query(k * 2 + 1, mid + 1, r, ql, qr);
    }

    // printf("ret %d,%d %lld %lld\n", l, r, maxi, node[k].cover);
    return maxi + node[k].cover;
}

int main() {
    scanf("%d%d%lld", &n, &q, &K);

    for (int i = 1; i <= n; i++) {
        scanf("%lld", &w[i]);
        sum_update(i, w[i]);
    }
    node_init(1, 0, n);

    while (q--) {
        int a = 0, b = 0;
        long long c = 0, d = 0;
        scanf("%d", &a);

        switch (a) {
            case 0:
                scanf("%d", &b);
                printf("%lld\n", node_query(1, 0, n, 0, b) - sum_query(n) + sum_query(b));
                break;

            case 1:
                scanf("%d%lld", &b, &c);
                d = c - w[b];
                sum_update(b, d);
                w[b] = c;
                node_update(1, 0, n, 0, b - 1, d);
                break;
        }
    }

    return 0;
}
