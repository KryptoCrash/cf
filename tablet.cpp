#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;


int main() {
    string s;
    cin >> s;

    ll n = s.length();

    vector<int> ar(n);
    for (int i = 0; i < n; i++) ar[i] = s[i] - 'a';

    vector<int> dp = vector<int>(26, INT_MAX);
    dp[ar[0]] = 0;

    for(int i = 0; i < n - 1; i++) {
        dp[ar[i + 1]] = min(dp[ar[i + 1]], dp[ar[i]] + 1);
    }

    cout << dp[ar[n - 1]] + 1 << endl;

    return 0;
}