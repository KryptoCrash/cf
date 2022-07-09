#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<ll>;
using vb = vector<bool>;

void solve() {
    string s;
    cin >> s;

    ll n = s.length();

    vb last(n);
    vi thing(26, -1);
    for (int i = 0; i < n; i++) {
        thing[s[i] - 'a'] = i;
    }
    for (int i = 0; i < 26; i++) {
        if (thing[i] != -1) last[thing[i]] = true;
    }

    string t;

    ll l, r;
    l = r = 0;

    vb chose(26);
    vi cnt(26);

    bool lastbad = false;

    while (true) {
        if (l >= r || lastbad) {
            bool works = false;

            for (int i = (lastbad ? r + 1 : l); i < n; i++) {
                cnt[s[i] - 'a']++;
                if (last[i] && !chose[s[i] - 'a']) {
                    r = i;
                    works = true;
                    break;
                }
            }

            if (!works) break;
        }
        lastbad = false;

        ll look = -1;
        for (int i = 25; i >= 0; i--) {
            if (cnt[i] > 0 && !chose[i]) {
                look = i;
                break;
            }
        }

        for (int i = l; i <= r; i++) {
            cnt[s[i] - 'a']--;
            if (s[i] - 'a' == look) {
                l = i + 1;
                chose[s[i] - 'a'] = true;
                t += s[i];
                if (s[r] - 'a' == look) lastbad = true;
                break;
            }
        }
    }

    cout << t << endl;
}

int main() {
    int t;
    cin >> t;
     while (t--) solve();

    return 0;
}