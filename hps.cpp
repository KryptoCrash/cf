#include <bits/stdc++.h>
using namespace std;

int main() {
	ifstream fin("hps.in");
	ofstream fout("hps.out");

	int n;
	fin >> n;

	vector<char> mv(n);

	for(int i = 0; i < n; i++) {
		fin >> mv[i];
	}

	vector<array<int, 3>> psum(n + 1);
	psum[0] = {0,0,0};
	for(int i = 0; i < n; i++) {
		psum[i + 1] = psum[i];
		if(mv[i] == 'H') psum[i + 1][0]++;
		else if(mv[i] == 'P') psum[i + 1][1]++;
		else if(mv[i] == 'S') psum[i + 1][2]++;
	}

	int best = 0;
	for(int i = 0; i < n; i++) {
		int lsum = max(psum[i][0], max(psum[i][1], psum[i][2]));
		int rsum = max(psum[n][0] - psum[i][0], max(psum[n][1] - psum[i][1], psum[n][2] - psum[i][2]));
		best = max(best, lsum + rsum);
	}

	fout << best << endl;

	return 0;
}
