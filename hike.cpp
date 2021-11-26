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

    ll n;
    cin >> n;

    vi a(n);
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll num_l = 0;
    ll best = 0;
    array<ll, 2> best_is;

    for (ll it = 0; it < 2; it++) {
        // find len of longest monotone segment
        ll curr = 1;
        for (ll i = 0; i < n; i++) {
            if(curr >= best) {
                best = curr;
            }
            if (i == n - 1) break;
            if (a[i + 1] > a[i])
                curr++;
            else
                curr = 1;
        }

        reverse(a.begin(), a.end());
    }

    for (ll it = 0; it < 2; it++) {
        // find len of longest monotone segment
        ll curr = 1;
        for (ll i = 0; i < n; i++) {
            if (curr == best) {
                best_is[it] = i;
                num_l++;
            }
            if (i == n - 1) break;
            if (a[i + 1] > a[i])
                curr++;
            else
                curr = 1;
        }

        reverse(a.begin(), a.end());
    }

    best_is[1] = n - 1 - best_is[1];

    if (num_l != 2 || best_is[0] != best_is[1] || best % 2 != 1) {
        cout << 0 << endl;
        return 0;
    }

    cout << 1 << endl;

    return 0;
}