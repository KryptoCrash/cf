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

    ll n, k;
    cin >> n >> k;

    vector<string> s(n);
    map<string, ll> cnt;
    for (ll i = 0; i < n; i++) {
        string chr;
        cin >> chr;
        s[i] = chr;
        cnt[s[i]]++;
    }

    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        for (ll j = i; j < n; j++) {
            string s1 = s[i];
            string s2 = s[j];
            string con;
            for (ll z = 0; z < k; z++) {
                if (s1[z] == s2[z]) con += s1[z];
                else {
                    if (s1[z] == 'S' && s2[z] == 'T') con += 'E';
                    if (s1[z] == 'T' && s2[z] == 'S') con += 'E';
                    if (s1[z] == 'T' && s2[z] == 'E') con += 'S';
                    if (s1[z] == 'E' && s2[z] == 'T') con += 'S';
                    if (s1[z] == 'E' && s2[z] == 'S') con += 'T';
                    if (s1[z] == 'S' && s2[z] == 'E') con += 'T';
                }
            }
            if(cnt.find(con) != cnt.end()) ans += max(0LL, cnt[con] - (s1 == con) - (s2 == con));
        }
    }

    assert(ans % 3 == 0);

    cout << ans / 3 << endl;

    return 0;
}