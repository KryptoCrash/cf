#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

void solve() {
    string s;
    cin >> s;

    ll n = s.length();

    bool works = false;

    for (int i = n - 1; i >= 1; i--) {
        ll x = s[i] - '0';
        ll y = s[i - 1] - '0';
        if (x + y > 9) {
            s[i - 1] = '0' + ((x + y) / 10);

            s[i] = '0' + ((x + y) % 10);
            works = true;
            break;
        }
    }

    if(!works) {
        string t;
        t += '0' + ((s[0] - '0') + (s[1] - '0'));
        for (int i = 2; i < n; i++) {
            t += s[i];
        }

        s = t;
    }

    cout << s << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--) solve();

    return 0;
}