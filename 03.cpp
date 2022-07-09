#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

const ll mod = 1e9 + 7;

void solve() {
    ll n;
    cin >> n;

    string s;
    string t;
    cin >> s;
    cin >> t;

    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());

    s += '0';
    t += '0';
    n++;

    vi psum(n + 1);
    
    for(int i = 0; i < n; i++) {
        psum[i + 1] = psum[i] + (s[i] == '+');
    }

    vi psum2(n + 1);
    
    for(int i = 0; i < n; i++) {
        psum2[i + 1] = psum2[i] + (t[i] == '+');
    }

    vi psum3(n + 1);
    for (int i = 0; i < n; i++) {
        psum3[i + 1] = psum3[i] + (s[i] == '0');
    }

    vi psum4(n + 1);
    for (int i = 0; i < n; i++) {
        psum4[i + 1] = psum4[i] + (t[i] == '0');
    }

    ll tot = 0;

    vector<vi> dp(n + 1, vi(n + 1));

    vector<vb> used(n + 1, vb(n + 1));

    // might be wrong
    dp[0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // move up on i
            if (s[i] == '+' && psum3[i] == 0 && psum4[j] == 0) {
                dp[psum[i + 1]][psum2[j]] += dp[psum[i]][psum2[j]];
                dp[psum[i + 1]][psum2[j]] %= mod;
                // tot += dp[i][j];
                // tot %= mod;
            } else if (s[i] == '0' && !used[psum[i]][psum2[j]] && psum3[i] == 0 && psum4[j] == 0) {
                tot += dp[psum[i]][psum2[j]];
                used[psum[i]][psum2[j]] = true;
            }

            // move up on j
            if (t[j] == '+' && psum3[i] == 0 && psum4[j] == 0) {
                dp[psum[i]][psum2[j + 1]] += dp[psum[i]][psum2[j]];
                dp[psum[i]][psum2[j + 1]] %= mod;
                // tot += dp[i][j];
                // tot %= mod;
            } else if (t[j] == '0' && !used[psum[i]][psum2[j]] && psum3[i] == 0 && psum4[j] == 0) {
                tot += dp[psum[i]][psum2[j]];
                used[psum[i]][psum2[j]] = true;
            }
        }
    }

    tot %= mod;
    if (tot < 0) tot += mod;
    cout << tot << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while(t--) solve();

    return 0;
}