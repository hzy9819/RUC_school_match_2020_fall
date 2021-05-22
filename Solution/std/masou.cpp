#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;

const int MAXD = 13;

const char *target[6] = { " ", " 11111", " 01111", " 00*11", " 00001", " 00000" };
char chess[7][7];

int ans = MAXD + 1, T;

bool check() {
    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= 5; j++)
            if (chess[i][j] != target[i][j])
                return false;

    return true;
}

void dfs(int i, int j, int d) {
    if (check()) {
        ans = d;
        return;
    }

    if (d >= ans - 1)
        return;

    // i2j1
    if (i >= 3) {
        // UL
        if (j >= 2) {
            swap(chess[i][j], chess[i - 2][j - 1]);
            dfs(i - 2, j - 1, d + 1);
            swap(chess[i][j], chess[i - 2][j - 1]);
        }
        // UR
        if (j <= 4) {
            swap(chess[i][j], chess[i - 2][j + 1]);
            dfs(i - 2, j + 1, d + 1);
            swap(chess[i][j], chess[i - 2][j + 1]);
        }
    }
    if (i <= 3) {
        // DL
        if (j >= 2) {
            swap(chess[i][j], chess[i + 2][j - 1]);
            dfs(i + 2, j - 1, d + 1);
            swap(chess[i][j], chess[i + 2][j - 1]);
        }
        // DR
        if (j <= 4) {
            swap(chess[i][j], chess[i + 2][j + 1]);
            dfs(i + 2, j + 1, d + 1);
            swap(chess[i][j], chess[i + 2][j + 1]);
        }
    }

    // i1j2
    if (i >= 2) {
        // LU
        if (j >= 3) {
            swap(chess[i][j], chess[i - 1][j - 2]);
            dfs(i - 1, j - 2, d + 1);
            swap(chess[i][j], chess[i - 1][j - 2]);
        }
        // RU
        if (j <= 3) {
            swap(chess[i][j], chess[i - 1][j + 2]);
            dfs(i - 1, j + 2, d + 1);
            swap(chess[i][j], chess[i - 1][j + 2]);
        }
    }
    if (i <= 4) {
        // LD
        if (j >= 3) {
            swap(chess[i][j], chess[i + 1][j - 2]);
            dfs(i + 1, j - 2, d + 1);
            swap(chess[i][j], chess[i + 1][j - 2]);
        }
        // RD
        if (j <= 3) {
            swap(chess[i][j], chess[i + 1][j + 2]);
            dfs(i + 1, j + 2, d + 1);
            swap(chess[i][j], chess[i + 1][j + 2]);
        }
    }
}

int main() {
    for (int i = 1; i <= 5; i++) scanf("%s", chess[i] + 1);

    bool flag = false;
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++)
            if (chess[i][j] == '*') {
                dfs(i, j, 0);
                flag = true;
                break;
            }

        if (flag)
            break;
    }

    if (ans > MAXD)
        printf("-1\n");
    else
        printf("%d\n", ans);

    return 0;
}
