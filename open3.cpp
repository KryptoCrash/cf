#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    ll n = s.length();

    ll q;
    cin >> q;

    vi a(n);

    for (ll i = 0; i < s.length(); i++) {
        if (s[i] == 'C') a[i] = 1;
        if (s[i] == 'O') a[i] = 2;
        if (s[i] == 'W') a[i] = 3;
    }

    vi xorsum(n + 1);
    
    for(ll i = 0; i < n; i++) {
        xorsum[i + 1] = xorsum[i] ^ a[i];
    }

    for (ll i = 0; i < q; i++) {
        ll l, r;
        cin >> l >> r;

        cout << (((xorsum[r] ^ xorsum[l - 1]) == 1) ? "Y" : "N");
    }

    cout << endl;

    return 0;
}