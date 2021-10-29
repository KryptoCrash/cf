#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t;
    cin >> n >> t; 

    vector<bool> a(n);
    for(int i = 0; i < n; i++) {
        char c;
        cin >> c;
        a[i] = c - '0';
    }

    // idea, bin search on possible starting cows, and k

    

    return 0;
}