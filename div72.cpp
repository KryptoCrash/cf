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

    if((n % 7) == 0) {
        cout << n << endl;
        return;
    }

    n = (n / 10) * 10;

    for(int i = 0; i < 10; i++) {
        if((n + i) % 7 == 0) {
            cout << n + i << endl;
            return;
        }
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