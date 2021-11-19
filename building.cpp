#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<bool> pos(1001);

    for(int i = 1; i < 400; i++) {
        for(int j = 1; j < 400; j++) {
            if (4 * i * j + 3 * i + 3 * j > 1000) continue;
            pos[4 * i * j + 3 * i + 3 * j] = true;
        }
    }

    vi a(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if(pos[a[i]]) ans++;
    }

    cout << n - ans << endl;

    return 0;
}