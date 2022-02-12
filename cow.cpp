#include <bits/stdc++.h>
using namespace std;

using ll = unsigned long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

const ll mod = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    vi a(n);
    vector<string> s(n);
    vi cnt(11);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        s[i] = to_string(a[i]);
        cnt[s[i].length()]++;
    }

    ll ans = 0;

    for (ll i = 0; i < n; i++) {
        // for when a[i] is x
        for (ll j = 0; j <= 10; j++) {
            string str = s[i];

            reverse(str.begin(), str.end());

            ll place = 0;
            ll ct = j;
            for (char c : str) {
                ll val = c - '0';
                ans += (((((cnt[j] % mod) * val) % mod) * ((ll)pow(10, place) % mod)) % mod);
                ans %= mod;
                if (ct == 0)
                    place++;
                else {
                    place += 2;
                    ct--;
                }
            }
        }

        for (ll j = 0; j <= 10; j++) {
            string str = s[i];
            reverse(str.begin(), str.end());

            ll place = 1;
            ll ct = j - 1;
            for (char c : str) {
                ll val = c - '0';
                ans += (((((cnt[j] % mod) * val) % mod) * ((ll)pow(10, place) % mod)) % mod);
                ans %= mod;
                if (ct == 0)
                    place++;
                else {
                    place += 2;
                    ct--;
                }
            }
        }
    }

    ans %= mod;
    if (ans < 0) ans += mod;

    cout << ans << endl;

    return 0;
}