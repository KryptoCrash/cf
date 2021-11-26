#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

void solve() {
    ll n, k;
    cin >> n >> k;

    vi a(n);
    vi s(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s[i] = a[i];
    }

    sort(s.begin(), s.end());

    int ans = 1;

    for(int i = 0; i < n-1; i++) {
        auto it = upper_bound(s.begin(), s.end(), a[i]);
        if (it == s.end() || *it != a[i + 1]) ans++;
    }

    cout << (ans <= k ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while(t--) solve();

    return 0;
}