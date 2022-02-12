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

    ll cnt0, cnt1;
    cnt0 = cnt1 = 0;
    for(char c : s) {
        if(c == '0') {
            cnt0++;
        } else
            cnt1++;
    }

    if(cnt0==cnt1) {
        cout << cnt0 - 1 << endl;
        return;
    }

    cout << min(cnt0, cnt1) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while(t--) solve();

    return 0;
}