#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

const ll INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    vi a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

    vi last(n, INF);
    vi nxt(n, INF);
    for (ll i = n - 1; i >= 0; i--) {
        nxt[i] = last[a[i]];
        last[a[i]] = i;
    }

    if (n < 2) {
        cout << 1 << endl;
        return 0;
    }

    ll l = 0;
    ll r = 1;

    if (a[l] == a[r]) l = r;

    ll ans = 2;

    for (ll i = 2; i < n; i++) {
        if (a[i] == a[l] && a[i] == a[r]) {
            l = r = i;
        } else if (a[i] == a[l] || a[i] == a[r]) {
            ans++;
            l = r = i;
        } else {
            if (nxt[l] > nxt[r]) {
                assert(l < i && nxt[l] > i);
                r = i;
            } else {
                assert(r < i && nxt[r] > i);
                l = i;
            }
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}