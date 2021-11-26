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

    ll n, k;
    cin >> n >> k;

    vi sum(n);
    vi ss(n);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            int a;
            cin >> a;
            sum[i] += a;
        }
    }

    ss = sum;

    sort(ss.begin(), ss.end(), greater<int>());

    for (int i = 0; i < n; i++) {
        cout << ((lower_bound(ss.begin(), ss.end(), sum[i] + 300, greater<int>()) - ss.begin()) < k ? "Yes" : "No") << endl;
    }

        return 0;
}