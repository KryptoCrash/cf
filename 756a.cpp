#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

void solve() {
    string n;
    cin >> n;

    ll l = n.length();

    bool works0 = false;
    bool works1 = false;
    bool works2 = false;

    ll i = 0;
    for (char c : n) {
        ll a = c - '0';

        if(a % 2 == 0) {
            works2 = true;
            if (i == 0) works1 = true;
            if (i == l - 1) works0 = true;
        }
        i++;
    }

    ll ans = -1;
    if (works0) ans = 0;
    else if(works1)
        ans = 1;
    else if(works2)
        ans = 2;

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