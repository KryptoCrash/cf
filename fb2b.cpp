#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

void solve() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    int base = n + m - 1;
    if (base > a || base > b) {
        cout << "Impossible" << endl;
        return;
    }

    cout << "Possible" << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(i == 0 && j == 0) {
                cout << a - base + 1;
            } else if (i == 0 && j == m - 1) {
                cout << b - base + 1;
            } else
                cout << 1;
            cout << " ";
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}