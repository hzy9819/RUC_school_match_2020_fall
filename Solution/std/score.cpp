#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
const int N = 1000050;
const int INF = 2147483647;
typedef long long ll;
ll n, s;
ll a[N];
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        ll ans = 0;
        scanf("%d%d", &n, &s);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        sort(a + 1, a + n + 1);
        a[n + 1] = INF;
        for (int i = 1; i <= n + 1; i++) {
            if (a[i] > s) {
                if (i <= (n + 1) / 2)
                    for (int j = i; j <= (n + 1) / 2; j++) ans += (a[j] - s);
                if (i > (n + 1) / 2)
                    for (int j = (n + 1) / 2; j <= i - 1; j++) ans += (s - a[j]);
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
