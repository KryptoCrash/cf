#include <bits/stdc++.h>

using namespace std;

const int maxn = 100;
const int maxk = 1e9;

int solve() {
    int n, k;
    cin >> n >> k;

    // data input
    int h[maxn];

    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    for (int i = 0; i < k; i++) {
        bool success = true;
        for (int j = 0; j < (n - 1); j++) {
            // Didnt pass this mountain
            if(h[j + 1] > h[j]) {
                h[j]++;
                success = false;
                if (i == k - 1) return j + 1;
                break;
            }
        }
        if (success) return -1;
    }

    return -1;
}

int main(int argc, char const *argv[]) {
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << endl;
    }

    return 0;
}
