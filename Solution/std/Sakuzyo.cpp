#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int N = 8;

struct Point {
    int x, y, z;
};

Point point[10];

long long edge[30];

int edge_n, T;

bool cmp(const long long &a, const long long &b) { return a < b; }

long long dis(const Point &a, const Point &b) {
    long long sum = ((long long)a.x - b.x) * ((long long)a.x - b.x);
    sum += ((long long)a.y - b.y) * ((long long)a.y - b.y);
    sum += ((long long)a.z - b.z) * ((long long)a.z - b.z);

    return sum;
}

bool check() {
    edge_n = 0;

    for (int i = 1; i < N; i++)
        for (int j = i + 1; j <= N; j++) edge[++edge_n] = dis(point[i], point[j]);

    sort(edge + 1, edge + edge_n + 1, cmp);

    //棱
    for (int i = 2; i <= 12; i++)
        if (edge[i] != edge[1])
            return false;

    //面对角线
    for (int i = 13; i <= 24; i++)
        if (edge[i] != edge[1] * 2)
            return false;

    //体对角线
    for (int i = 25; i <= 28; i++)
        if (edge[i] != edge[1] * 3)
            return false;

    return true;
}

int main() {
    scanf("%d", &T);

    while (T--) {
        for (int i = 1; i <= N; i++) scanf("%d%d%d", &point[i].x, &point[i].y, &point[i].z);

        if (check())
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
