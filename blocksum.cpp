#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

ll n;
int main() {
    int K = 0;
    cin >> n;

    vector<vi> a(n, vi(n, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    
    for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                psum[i][j] = psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1] + a[i][j];
            }
    }

    vector<vi> ans(n, vi(n, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ans[i][j] = get_sum(i - K, j - K, i + K + 1, j + K + 1);
        }
    }

    return 0;
}