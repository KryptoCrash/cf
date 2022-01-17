#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <chrono>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#define ld long double
#define ll long long
#define ull unsigned long long
#define inf 1e9

using namespace std;

void solve() {
    ll mod = 998244353;
    int n;
    cin >> n;
    vector<int> s(n);
    vector<pair<ll, ll>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
        cin >> arr[i].second;
        cin >> s[i];
    }
    arr.emplace_back(arr[n - 1].first + 1, 0);
    vector<ll> ans(n);
    vector<ll> pre(n);
    ans[0] = arr[1].first - arr[0].second;
    pre[0] = ans[0];
    set<pair<ll, ll>> visited;
    visited.emplace(arr[0].first, 0);
    // for(int i=0;i<n;i++){
    //     cout<<arr[i].first<<" "<<arr[i].second<<endl;
    // }
    for (int i = 1; i < n; i++) {
        int best = -1;
        auto next = visited.lower_bound(pair<ll, ll>(arr[i].second, 0));
        // for(auto a:visited){
        //     cout<<a.first<<" "<<a.second<<endl;
        // }
        // cout<<endl;
        if (next != visited.end()) {
            best = next->second;
            // cout<<arr[i].second<<endl;
            // cout<<next->first<<" "<<next->second<<endl;
        }
        visited.emplace(arr[i].first, i);
        if (best == -1) {
            ans[i] = arr[i + 1].first - arr[i].second;
            pre[i] = pre[i - 1] + ans[i];
            ans[i] = ((ans[i] % mod) + mod) % mod;
            pre[i] = ((pre[i] % mod) + mod) % mod;
            continue;
        }
        ans[i] = arr[best].first - arr[i].second;
        ans[i] += pre[i - 1] - pre[best] + ans[best];
        ans[i] += arr[i + 1].first - arr[i].first;
        pre[i] = pre[i - 1] + ans[i];
        ans[i] = ((ans[i] % mod) + mod) % mod;
        pre[i] = ((pre[i] % mod) + mod) % mod;
    }
    ll sm = 0;
    for (int i = 0; i < n; i++) {
        if (s[i]) {
            sm += ans[i];
        } else {
            sm += arr[i + 1].first - arr[i].first;
        }
        sm %= mod;
    }
    // for(int i=0;i<n;i++){
    //     cout<<ans[i]<<" ";
    // }
    // cout<<endl;
    // for(int i=0;i<n;i++){
    //     cout<<pre[i]<<" ";
    // }
    // cout<<endl;
    sm += arr[0].first;
    sm %= mod;
    cout << sm << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(15) << fixed;
    int t = 1;
    // cin >> t;
    for (int c = 0; c < t; c++) {
        // cout<<"Case #"<<c+1<<": ";
        solve();
    }
}