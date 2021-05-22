#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    string s;
    int c = 0;
    for (int i = 1; i <= 2; i++) {
        if (a == b and a == 0) {
            cout << "! " << c << endl;
            fflush(stdout);
            return 0;
        }
        c = a + b;
        cout << "? " << c << endl;
        fflush(stdout);
        cin >> s;
        if (s == "YES") {
            cout << "! " << c << endl;
            fflush(stdout);
            return 0;
        }

        c = a - b;
        cout << "? " << c << endl;
        fflush(stdout);
        cin >> s;
        if (s == "YES") {
            cout << "! " << c << endl;
            fflush(stdout);
            return 0;
        }

        c = a * b;
        cout << "? " << c << endl;
        fflush(stdout);
        cin >> s;
        if (s == "YES") {
            cout << "! " << c << endl;
            fflush(stdout);
            return 0;
        }

        c = a ^ b;
        cout << "? " << c << endl;
        fflush(stdout);
        cin >> s;
        if (s == "YES") {
            cout << "! " << c << endl;
            fflush(stdout);
            return 0;
        }
    }
    c = a * b;
    cout << "? " << c << endl;
    fflush(stdout);
    cin >> s;
    if (s == "YES") {
        cout << "! " << c << endl;
        fflush(stdout);
        return 0;
    }

    c = a ^ b;
    cout << "? " << c << endl;
    fflush(stdout);
    cin >> s;
    if (s == "YES") {
        cout << "! " << c << endl;
        fflush(stdout);
        return 0;
    }
    return 0;
}
