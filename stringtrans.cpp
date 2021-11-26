#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

void solve() {
    string s;
    cin >> s;
    int n = s.length();

    vi mp(26);
    vi path;
    for (int i = n - 1; i >= 0; i--) {
        if (!mp[s[i]-'a']) path.push_back(s[i]-'a');
        mp[s[i]-'a']++;
    }

    reverse(path.begin(), path.end());

    vi cnt(26);
    int left = 0;
    string f;
    for (int i = 0; i < path.size(); i++) {
        cnt[path[i]] = mp[path[i]] / (i + 1);
        left += cnt[path[i]];
        f+='a'+path[i];
    }

    string t;
    for (int i = 0; i < n; i++) {
        if (left == 0) break;
        t += s[i];
        left--;
    }

    // check
    string check;
    string oldt;
    oldt = t;
    for (int v : path) {
        check += t;
        string nt;
        for(char ch : t) {
            if(ch != ('a'+v)) nt += ch;
        }
        t = nt;
    }

    if (t != "" || check != s) {
        cout << -1 << endl;
        return;
    }

    cout << oldt << " " << f << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--) solve();

    return 0;
}