#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

const ll mod = 1e9 + 7;

ll n, m;
vector<set<ll>> adj;
vector<vector<ll>> dp;
vector<vector<bool>> visit;

ll dfs(ll mask, ll curr) {
    if(mask == (1 << n) - 1 && curr == 0) return 1;
    if(mask == (1 << n) - 1 || curr == 0) return 0;
    if(visit[mask][curr]) return dp[mask][curr];

    ll sum = 0;
    for(ll c : adj[curr]) {
        if(((1 << c) & mask) == 0) {
            sum += dfs((1 << c) | mask, c);
            sum %= mod;
        }
    }

    visit[mask][curr] = true;
    dp[mask][curr] = sum;

    return sum;
}

int main() {
    cin >> n >> m;

    adj = vector<set<ll>>(n, set<ll>{});
    dp = vector<vector<ll>>(1 << n, vector<ll>(n, 0));
    visit = vector<vector<bool>>(1 << n, vector<bool>(n, false));
    for(ll i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        adj[b].insert(a);
    }

    // dfs from end
    cout << dfs(1 << (n - 1), n - 1) % mod << endl;
    
    return 0;
}