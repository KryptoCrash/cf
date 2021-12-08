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

    ll n, q;
    cin >> n >> q;

    string s;
    cin >> s >> ws;

    ll sum = 0;

    for (ll i = 0; i < n - 2; i++) {
        if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c') sum++;
    }

    for (ll j = 0; j < q; j++) {
        ll i;
        char c;
        cin >> i >> c;
        i--;

        ll bsum = 0;

        for (ll k = i - 2; k <= i; k++) {
            if (k + 2 >= n || k < 0) continue;
            if (s[k] == 'a' && s[k + 1] == 'b' && s[k + 2] == 'c') bsum++;
        }

        s[i] = c;

        ll nsum = 0;

        for (ll k = i - 2; k <= i; k++) {
            if (k + 2 >= n || k < 0) continue;
            if (s[k] == 'a' && s[k + 1] == 'b' && s[k + 2] == 'c') nsum++;
        }

        sum += nsum - bsum;
        cout << sum << endl;
    }

    return 0;
}