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

    int n;
    cin >> n;

    vi mn(1 << 9, 1e9);
    mn[0] = -1;

    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        for (int j = 0; j < 512; j++) {
            if(a > mn[j]) mn[j ^ a] = min(mn[j ^ a], a);
        }
    }

    vi ans;
    for (int i = 0; i < (1 << 9); i++) {
        if (mn[i] != (ll)1e9) ans.push_back(i);
    }

    cout << ans.size() << endl;
    for(ll x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}