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

    ll n, x;
    cin >> n >> x;
    x--;

    vi a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

    vector<int> vis(n);

    function<void(int)> dfs = [&](int v) {
        if(vis[v]) return;
        vis[v] = true;

        dfs(a[v]);
    };

    dfs(x);

    int ac = 0;
    ac = accumulate(vis.begin(), vis.end(), ac);

    cout << ac << endl;

    return 0;
}