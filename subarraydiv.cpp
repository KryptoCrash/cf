#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	int n;
	cin >> n;

	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}

	// do psum with remainders
	vector<ll> cnt(n);
	fill(cnt.begin(), cnt.end(), 0);
	cnt[0] = 1;
	int c_sum = 0;
	for(int i = 0; i < n; i++) {
		c_sum += (n + (a[i] % n) % n);
		c_sum %= n;
		cnt[c_sum]++;
	}

	ll all = 0;
	for(int i = 0; i < n; i++) {
		all += (cnt[i] * (cnt[i] - 1)) / 2;
	}

	cout << all << endl;

	return 0;
}
