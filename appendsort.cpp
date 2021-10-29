#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

bool greaterThan(string s1, string s2) {
    if (s1.length() > s2.length()) return true;
    if (s1.length() < s2.length()) return false;
    if (s1 == s2) return false;
    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] > s2[i]) return true;
        if (s1[i] < s2[i]) return false;
    }
    assert(false);
}

bool lessThan(string s1, string s2) {
    if (s1.length() > s2.length()) return false;
    if (s1.length() < s2.length()) return true;
    if (s1 == s2) return false;
    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] > s2[i]) return false;
        if (s1[i] < s2[i]) return true;
    }
    assert(false);
}

string add1(string s1) {
    int n = s1.length();
    bool carry = false;
    for (int i = n - 1; i >= 0; i--) {
        int val = s1[i] - '0';
        if (val == 9) {
            s1[i] = 0;
            carry = true;
        } else {
            s1[i] = (val + 1) + '0';
            carry = false;
            break;
        }
    }

    if (carry) s1 = "1" + s1;
    return s1;
}

ll solve() {
    ll n;
    cin >> n;

    vector<string> a(n);
    for (ll i = 0; i < n; i++) {
        ll c;
        cin >> c;
        a[i] = to_string(c);
    }

    string prev = a[0];
    ll sum = 0;
    for (ll i = 1; i < n; i++) {
        string val = a[i];
        if (greaterThan(val, prev)) {
            prev = val;
            continue;
        }

        if (val == prev) {
            prev = prev + "0";
            sum++;
            continue;
        }

        string newprev;

        for (ll j = 0; j < ((ll)val.length()); j++) {
            newprev += prev[j];
        }

        if (newprev == val) {
            if (add1(prev).substr(0, val.length()) != newprev) {
                while (lessThan(val, prev)) {
                    val += "0";
                    sum++;
                }

                prev = val;
            } else {
                prev = add1(prev);
                sum += prev.length() - val.length();
            }
            continue;
        } else {
            while (lessThan(val, prev)) {
                val += "0";
                sum++;
            }

            prev = val;

            continue;
        }
    }

    return sum;
}

int main() {
    ll t;
    cin >> t;
    for (ll i = 0; i < t; i++) {
        cout << "Case #" << i + 1 << ": " << solve() << endl;
    }

    return 0;
}