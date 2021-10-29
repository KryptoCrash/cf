#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

int main() {
    string s;
    cin >> s;

    bool a, c, g, t;

    int ans = 0;
    for (char ch : s) {
        if (a && c && g && t) {
            a = c = g = t = false;
            ans++;
        }
        switch (ch) {
            case 'A':
                a = true;
                break;
            case 'C':
                c = true;
                break;
            case 'G':
                g = true;
                break;
            case 'T':
                t = true;
        }
    }

    cout << ans + 1 << endl;

    return 0;
}