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

    string a, b, c;
    cin >> a >> b >> c;

    vi cnt0(3);
    vi cnt1(3);

    for (ll i = 0; i < 2*n; i++) {
        if (a[i]=='0')
            cnt0[0]++;
        else
            cnt1[0]++;

        if (b[i] == '0')
            cnt0[1]++;
        else
            cnt1[1]++;
        if (c[i] == '0')
            cnt0[2]++;
        else
            cnt1[2]++;
    }

    string s1;
    string s2;
    char ch = '0';

    if(cnt0[0] >= n && cnt0[1] >= n) {
        s1 = a;
        s2 = b;
        ch = '0';
    } else if (cnt1[0] >= n && cnt1[1] >= n) {
        s1 = a;
        s2 = b;
        ch = '1';
    } else if (cnt0[0] >= n && cnt0[2] >= n) {
        s1 = a;
        s2 = c;
        ch = '0';
    } else if (cnt1[0] >= n && cnt1[2] >= n) {
        s1 = a;
        s2 = c;
        ch = '1';
    } else if (cnt0[1] >= n && cnt0[2] >= n) {
        s1 = b;
        s2 = c;
        ch = '0';
    } else if (cnt1[1] >= n && cnt1[2] >= n) {
        s1 = b;
        s2 = c;
        ch = '1';
    }

    ll left = n;
    ll i = 0;
    ll j = 0;
    string res;
    while(left > 0) {
        while(s1[i] != ch) {
            res += s1[i++];
        }
        while (s2[j] != ch) {
            res += s2[j++];
        }
        res += ch;
        i++, j++, left--;
    }

    while (i < 2 * n) {
        res += s1[i++];
    }

    while(j < 2 * n) {
        res += s2[j++];
    }

    assert(res.size() <= 3 * n);

    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while(t--) solve();

    return 0;
}