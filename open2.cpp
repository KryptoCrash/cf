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

    string s;
    string t;
    cin >> s;
    cin >> t;

    ll q;
    cin >> q;

    map<pair<char, char>, bool> works;

    for (char i = 'a'; i <= 'r'; i++) {
        for (char j = 'a'; j <= 'r'; j++) {
            
            string temps = "";
            string tempt = "";
            for (int a = 0; a < s.length(); a++) {
                if (s[a] == i || s[a] == j) temps += s[a];
            }

            for (int a = 0; a < t.length(); a++) {
                if (t[a] == i || t[a] == j) tempt += t[a];
            }
            works[{i, j}] = temps == tempt;
        }
    }

    for (int i = 0; i < q; i++) {
        string que;
        cin >> que;

        bool ok = true;

        for(char c : que) {
            for(char d : que) {
                if (!works[{c, d}]) ok = false;
            }
        }

        cout << (ok ? "Y" : "N");
    }

    cout << endl;

    return 0;
}