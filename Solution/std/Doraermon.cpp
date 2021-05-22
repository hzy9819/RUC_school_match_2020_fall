#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int N = 200050;
int n, m;
int a[N];
int pre = 0, totans = 0;
bool check(int mid) {
    int ans = 0;
    int pack = 0;
    for (int i = 1; i <= m; i++) {
        ans += a[i];
        if (ans > mid) {
            pack++;
            ans = a[i];
        }
    }
    if (ans != 0)
        pack++;
    if (pack <= n)
        return true;
    else
        return false;
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) cin >> a[i];
    sort(a + 1, a + m + 1);
    for (int i = 1; i <= m; i++) pre += a[i];
    int l = a[m], r = pre;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            r = mid - 1;
            totans = mid;
        } else
            l = mid + 1;
    }
    cout << totans << endl;
    return 0;
}
