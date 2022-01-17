#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

const ll mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m, k, r, c;
    cin >> n >> m >> k >> r >> c;

    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    function<ll(ll, ll)> binpow = [&](ll x, ll y) {
        assert(y >= 0);
        
        x %= mod;
        
        ll res = 1;
        
        while (y > 0) {
            if (y % 2 == 1) res = res * x % mod;
            x = x * x % mod;
            y /= 2;
        }
        
        return res;
    };

    ll space = n*m;
    if(!(x1 == x2 && y1 == y2)) space -= r * c;
    
    cout << binpow(k, space) << endl;

    return 0;
}