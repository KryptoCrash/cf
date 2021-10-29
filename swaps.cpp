#include <bits/stdc++.h>
using namespace std;

using ll = int;
using pi = pair<ll, ll>;
using vi = vector<ll>;
const int INF = 1e9;

void solve() {
    int n;
    cin >> n;

    vector<pi> a;
    int last_a = INF;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x < last_a) {
            a.push_back({x, i});
            last_a = x;
        }
    }

    vector<pi> b;
    int last_b = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x > last_b) {
            b.push_back({x, i});
            last_b = x;
        }
    }

    int best = INF;

    int bptr = b.size() - 1;
    for (int i = 0; i < a.size(); i++) {
        while (bptr >= 0 && a[i].first < b[bptr].first) {
            bptr--;
        }

        best = min(best, a[i].second + b[bptr + 1].second);
    }

    cout << best << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}