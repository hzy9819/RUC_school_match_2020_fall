#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

const int MAXN = 100010;

char code[MAXN];

short x;

bool is_p = true;

void p(int i) {
    x = 0;

    for (int j = i; j <= i + 15; j++) x = ((x << 1) | (code[j] - '0'));
}

void d(int i) {
    if (code[i] == '0')
        x--;
    else
        x++;
}

int main() {
    scanf("%s", code);

    for (int i = 0; code[i]; i += 16) {
        p(i);

        if (abs(x) >= 32768) {
            is_p = false;
            break;
        }
    }

    if (is_p)
        for (int i = 0; code[i]; i += 16) {
            p(i);
            printf("%d\n", x);
        }
    else {
        x = 0;

        for (int i = 0; code[i]; i++) {
            d(i);
            printf("%d\n", x);
        }
    }

    return 0;
}
