#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

int solve() {
    int n;
    cin >> n;

    vi a(n);
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        for (int j = 0; j < y; j++) {
            a.emplace_back(x);
        }
    }

    int best = 0;
    for (int i = 1; i < pow(2, a.size() - 1) - 1; i++) {
        int sum = 0;
        int prod = 1;
        for (int j = 0; j < a.size(); j++) {
            int val = (i >> j & 1);
            if (val == 0) sum += a[j];
            else
                prod *= a[j];
        }
        if (sum == prod) best = max(best, sum);
    }

    return best;
}

int main() {
    ll t;
    cin >> t;
    for (ll i = 0; i < t; i++) {
        cout << "Case #" << i + 1 << ": " << solve() << endl;
    }

    return 0;
}