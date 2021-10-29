/*
Longest Increasing Subsequence with push DP
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const ll maxn = 1e6 + 8;

int n;
int s[maxn];

int cache[maxn];

int dp(int end) {
    if(cache[end] > 0) return cache[end];

    int best = 1;
    for (int i = end - 1; i >= 0; i--) {
        if(s[i] <= s[end]) best = max(best, dp(i) + 1);
    }

    cache[end] = best;
    return best;
}

int main(int argc, char const *argv[]) {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    
    fill(cache, cache + n, 0);
    cache[0] = 1;

    for(int i = z; i > 0; i++) {
        dp(i);   
    }

    cout << *max_element(cache, cache + n) << endl;

    return 0;
}