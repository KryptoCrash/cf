#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int maxn = 2e5;

bool ok(int mn, int mx) { return mx - mn <= 2; }

ll solve() {
	ll sum = 0;

	int n;
	cin >> n;

	int a[maxn];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n);

	int lo = 0;
	for(int mn = 0; mn < n; mn++) {
		int hi = n - 1;

		// bin search for max 
		while(lo < hi) {
			int mx = (hi + lo + 1) / 2;
			if(ok(a[mn], a[mx])) {
				lo = mx;
			} else {
				hi = mx - 1;
			}
		}

		// Calculate possible tuples in range (mn, mx)
		ll p = lo - mn - 1;
		sum += (p * p + p) / 2;
	}

	return sum;
}

int main() {
	int t;
	cin >> t;

	while(t--) {
		cout << solve() << endl;
	}

	return 0;
}
