#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ifstream fin("div7.in");
	ofstream fout("div7.out");

	ll n;
	fin >> n;

	vector<ll> a(n);
	for(ll i = 0; i < n; i++) {
		fin >> a[i];
	}

	vector<ll> psum(n + 1);
	psum[0] = 1;
	for(ll i = 0; i < n; i++) {
		psum[i + 1] = psum[i] + a[i];
		psum[i] %= 7;
	}

	// get left and rightmost point divisble by n
	ll best = 0;
	for(ll i = 0; i < 7; i++) {
		ll l = 0;
		ll r = 0;
		for(ll j = 0; j <= n; j++) {
			if(psum[j] == i) {
				l = j;
				break;
			}
		}

		for(ll j = n; j >= 0; j--) {
			if(psum[j] == i) {
				r = j;
				break;
			}
		}

		best = max(best, r - l);
	}
	
	fout << best << endl;

	return 0;
}
