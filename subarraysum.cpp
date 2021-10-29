#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int main() {
	int n, x;
	cin >> n >> x;

	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	ll sum = 0;
	map<ll, ll> bounds;
	bounds[0] = 1;
	for(int i = 0; i < n; i++) {
		sum += a[i];
		bounds[sum]++;
	}

	ll all = 0;
	for(auto l : bounds) {
		if(bounds.find(l.first + x) == bounds.end()) continue;
		all += l.second * (bounds[l.first + x] - 1);
	}

	if(x == 0) all /= 2;

	cout << all << endl;
	
	return 0;
}
