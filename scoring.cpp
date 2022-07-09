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

    ll s, h;
    cin >> s >> h;

    vector<double> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    double sum = 0;
    for (int i = s; i < n-h; i++) {
        sum += a[i];
    }

    cout << (sum / (n - h - s)) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while(t--) solve();

    return 0;
}