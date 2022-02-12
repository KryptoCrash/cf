#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

int op(int a, int b) {
    return min(a, b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t, n, k;
    cin >> t >> n >> k;

    vi p(n);
    vi w(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i] >> w[i];
    }
    
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            
        }
    }

    return 0;
}