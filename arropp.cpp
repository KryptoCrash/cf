#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve(){
    ll n;
    cin>>n;
    
    vi a(n);
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    Tree<pi> ac;
    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        ac.insert({a[i], i});
        ll f = ac.order_of_key({a[i], 0});
        ll u = i+1-ac.order_of_key({a[i], n});
        ans += min(f, u);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--) solve();

    return 0;
}