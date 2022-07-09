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

    string s;
    string t;
    cin >> s;
    cin >> t;

    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());

    vector<vector<vi>> dp(n, vector<vi>(n, vi(2)));
    dp[0][0][0] = dp[0][0][1] = 1;

    

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int nxt = 0; nxt < 2; nxt++) {
                


            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while(t--) solve();

    return 0;
}