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

    vector<string> s(n);

    for (ll i = 0; i < n; i++) {
        cin >> s[i];
    }

    bool works = false;

    for (ll i = 0; i < n; i++) {
        if (s[i].length() == 1) works = true;
        if ((s[i].length() == 2) && (s[i][0] == s[i][1])) works = true;
        if ((s[i].length() == 3) && ((s[i][0] == s[i][1]) && (s[i][0] == s[i][2]))) works = true;
    }

    map<string, ll> mp;
    for (ll i = 0; i < n; i++) {
        mp[s[i]] = i;
    }

    for (ll i = 0; i < n; i++) {
        if (s[i].length() == 3) {
            string fs = s[i].substr(0, 3);
            reverse(fs.begin(), fs.end());
            if (mp.find(fs) != mp.end()) {
                if (mp[fs] > i) works = true;
            }
            string fs2 = s[i].substr(0, 2);
            reverse(fs2.begin(), fs2.end());
            if (mp.find(fs2) != mp.end()) {
                if (mp[fs2] > i) works = true;
            }
        }
        if(s[i].length() == 2) {
            string fs = s[i].substr(0, 2);
            reverse(fs.begin(), fs.end());
            if (mp.find(fs) != mp.end()) {
                if (mp[fs] > i) works = true;
            }
        }
    }

    map<string, ll> mp2;
    for (ll i = n - 1; i >= 0; i--) {
        mp2[s[i]] = i;
    }

    for (ll i = n - 1; i >= 0; i--) {
        if (s[i].length() == 3) {
            string fs = s[i].substr(0, 3);
            reverse(fs.begin(), fs.end());
            if (mp2.find(fs) != mp2.end()) {
                if (mp2[fs] < i) works = true;
            }
            string fs2 = s[i].substr(1, 3);
            reverse(fs2.begin(), fs2.end());
            if (mp2.find(fs2) != mp2.end()) {
                if (mp2[fs2] < i) works = true;
            }
        }
        if (s[i].length() == 2) {
            string fs = s[i].substr(0, 2);
            reverse(fs.begin(), fs.end());
            if (mp2.find(fs) != mp2.end()) {
                if (mp2[fs] < i) works = true;
            }
        }
    }

    cout << (works ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--) solve();

    return 0;
}