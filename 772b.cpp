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

    vi a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    vb locmax(n);

    for (ll i = 1; i < n - 1; i++) {
        if (a[i] > a[i - 1] && a[i] > a[i + 1]) locmax[i] = true;
    }

    ll sum = 0;

    for (ll i = 1; i < n; i++) {
        if (locmax[i - 1]) {
            if (i != n - 1) {
                a[i] = max(a[i - 1], a[i + 1]);
                locmax[i - 1] = false;
                locmax[i] = false;
                locmax[i + 1] = false;
            } else {
                a[i] = a[i - 1];
                locmax[i - 1] = false;
                locmax[i] = false;
            }

            sum++;
        }
    }

    cout << sum << endl;

    for (ll i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--) solve();

    return 0;
}