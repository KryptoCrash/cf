#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int a = n - 1;
    int b = 0;
    for (int i = 0; i < 100; i++) {
        bool jumped = false;
        a--;
        if (a < 0) a = n - 1;
        b++;
        if (b >= n) b = 0;
        if (a == b) {
            b++;
            jumped = true;
        }
        if (b >= n) b = 0;

        cout << a << " " << b << (jumped ? "!" : "") << endl;
    }

    return 0;
}