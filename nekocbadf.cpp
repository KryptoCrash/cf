#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

const int INF = 1e9;

// Recursive function to return gcd of a and b
long long gcd(long long int a, long long int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to return LCM of two numbers
long long lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll a, b;
    cin >> a >> b;

    int best = INF;
    int bestk = -1;
    cout << lcm(a, b) - max(a, b) << endl;
    for (int k = 0; k < lcm(a, b) - max(a, b); k++) {
        if (lcm(a + k, b + k) < best) best = lcm(a + k, b + k), bestk = k;
        cout << k << " " << a + k << " " << b + k << " " << lcm(a + k, b + k) << endl;
    }

    cout << best << " " << bestk << endl;

    return 0;
}