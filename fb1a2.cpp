#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

const int INF = 1e9;
const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;

    vector<char> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    char c = '\0';
    int ans = 0;
    int fixed = 0;
    int n_fixed = 0;
    int contrib = 0;
    int first_non_f = -1;
    int second_non_f = -1;
    int f_sum = 0;
    ll real_n = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == '.') {
            f_sum += real_n * (fixed + n_fixed + 1);
            real_n *= 2;
            if (first_non_f == -1) continue;

            // code for dupe

            // calc additional answer
            int new_ans = 0;
            new_ans += contrib * n;

            // add fixed to some subarray of the contrib
            char first_c = a[first_non_f];
            if ((first_c == 'X' && c == 'O') || (first_c == 'O' && c == 'X')) {
                new_ans += fixed * (n - first_non_f);
                if(second_non_f == -1) second_non_f = first_non_f + real_n;
            }

            fixed += n_fixed + 1;

            if (second_non_f != -1) new_ans += n_fixed + 1 * (n - second_non_f);
            contrib %= MOD;
            fixed %= MOD;
            n_fixed %= MOD;
            ans %= MOD;
            contrib += contrib + new_ans - (contrib * n + ans);
            cout << "CoNTRIB: " << contrib << endl;
            ans += new_ans;
            ans %= MOD;

            continue;
        }
        real_n++;
        if (a[i] == 'F') n_fixed++;
        if (a[i] == 'O') {
            if (first_non_f == -1) first_non_f = i;
            if (c == 'X') {
                if (first_non_f != -1 && second_non_f == -1) second_non_f = i;
                contrib += fixed;
            }
            fixed += n_fixed + 1;
            n_fixed = 0;
            c = 'O';
        }
        if (a[i] == 'X') {
            if (first_non_f == -1) first_non_f = i;
            if (c == 'O') {
                if (first_non_f != -1 && second_non_f == -1) second_non_f = i;
                contrib += fixed;
            }
            fixed += n_fixed + 1;
            n_fixed = 0;
            c = 'X';
        }
        contrib %= MOD;
        fixed %= MOD;
        n_fixed %= MOD;
        ans %= MOD;
        ans += contrib;
        ans %= MOD;

        cout << i << "> " << contrib << " " << fixed << " " << n_fixed << " " << ans << endl;
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}