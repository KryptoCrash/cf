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

    vi suf(n + 1);
    vi in(n + 1);
    ll mex = 0;
    for (ll i = n - 1; i >= 0; i--) {
        in[a[i]]++;
        while(true) {
            if (in[mex] == 0) break;
            mex++;
        }
        suf[i] = mex;
    }

    vi b;
    ll cur = 0;
    ll cmex = 0;
    stack<ll> upd;
    vi freq(n + 1);
    for (ll i = 0; i < n; i++) {
        upd.push(a[i]);
        freq[a[i]]++;
        while (true) {
            if (freq[cmex] == 0) break;
            cmex++;
        }

        if(cmex >= suf[cur]) {
            cur = i + 1;
            while(!upd.empty()) {
                ll top = upd.top();
                freq[top]--;
                upd.pop();
            }
            b.push_back(cmex);
            cmex = 0;
        }
    }

    cout << b.size() << endl;
    for (ll i : b) {
        cout << i << " ";
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