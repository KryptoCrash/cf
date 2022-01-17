#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

void solve() {
    ll a, b, c;
    cin >> a >> b >> c;
    ll sum = a + b + c;
    ll ops = sum / 9;
    
    cout << ((sum % 9 == 0 && min(a, min(b, c)) >= ops) ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while(t--) solve();

    return 0;
}