#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

void solve() {
    ll n;
    string s;
    cin >> s;

    n = s.length();

    vector<array<int, 2>> p1(n + 1);
    for (int i = 0; i < n; i++) {
        p1[i + 1][0] = p1[i][0];
        p1[i + 1][1] = p1[i][1];
        if (s[i] == '[' || s[i] == ']') {
            p1[i + 1][i % 2]++;
        }
    }

    ll q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;

        ll ev = p1[r][0] - p1[l - 1][0];
        ll odd = p1[r][1] - p1[l - 1][1];

        cout << abs(ev - odd) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while(t--) solve();

    return 0;
}