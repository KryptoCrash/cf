#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n;
    cin >> n;

    string s;
    cin >> s;

    string match[] = {
        "aa",
        "aba",
        "aca",
        "abca",
        "acba",
        "abbacca",
        "accabba"
    };


    for(string m : match) {
        if(s.find(m) != s.npos) {
            cout << m.length() << endl;
            return;
        }
    }

    cout << -1 << endl;

    return;
}

int main() {
    ll t;
    cin >> t;
    while (t--) solve();

    return 0;
}