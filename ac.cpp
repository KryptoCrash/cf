#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

void solve() {
    ll n;
    cin >> n;

    string s;
    cin >> s;

    ll cnt = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') cnt++;
        if (s[i] == 'C') ans += cnt;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while(t--) solve();

    return 0;
}