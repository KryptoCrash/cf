#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int d = j - i;
            if (d * 2 < n) {
                cout << 1;
            } else if (d * 2 == n) {
                cout << 0;
            } else {
                cout << -1;
            }
            cout << " ";
        }
    }
    cout << endl;
}

int main(int argc, char const *argv[]) {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
