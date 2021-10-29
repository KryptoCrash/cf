#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

const int INF = 1e9;

void solve() {
    int n;
    cin >> n;

    vector<char> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int best_o = 0;
    int best_x = 0;

    for (int i = 0; i < n; i++) {
        int old_o = best_o;
        int old_x = best_x;

        char c = a[i];

        if (c == 'F') {
            best_o = min(old_o, old_x + 1);
            best_x = min(old_x, old_o + 1);
        };
        if (c == 'O') {
            best_o = min(old_o, old_x + 1);
            best_x = INF;
        }
        if (c == 'X') {
            best_x = min(old_x, old_o + 1);
            best_o = INF;
        }
    }

    cout << min(best_o, best_x) << endl;
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