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
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    bool works = true;

    for (int i = 1; i < n; i++) {
        if(a[i - 1] > a[i]) {
            works = false;
            
        }
    }

    cout << (works ? "NO" : "YES") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while(t--) solve();

    return 0;
}