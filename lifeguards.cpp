#include <bits/stdc++.h>
using namespace std;

using pi = pair<int, int>;

const int maxn = 1e5 + 8;

int main() {
    ifstream fin("lifeguards.in");
    ofstream fout("lifeguards.out");

    int n;
    fin >> n;

    priority_queue<array<int, 3>> ev;
    pi a[maxn];
    for (int i = 0; i < n; i++) {
        fin >> a[i].first >> a[i].second;
        ev.push({-a[i].first, 1, i});
        ev.push({-a[i].second, -1, i});
    }

    set<int> sweeped_cows;
    int no_overlap_s = -1;
    int last_empty = 0;
    int ans[maxn];
    int tot = 0;
    memset(ans, 0, sizeof(ans));

    while (!ev.empty()) {
        array<int, 3> top = ev.top();
        int time = -top[0];
        int type = top[1];
        int cow_i = top[2];
        ev.pop();

        int org = sweeped_cows.size();
        int cow_sweep_i;
        if (org == 1) cow_sweep_i = *sweeped_cows.begin();
        if (type == 1) sweeped_cows.insert(cow_i);
        if (type == -1) sweeped_cows.erase(cow_i);
        if (org == 1) {
            ans[cow_sweep_i] += time - no_overlap_s;
        }
        if (sweeped_cows.size() == 1) {
            no_overlap_s = time;
        }
        if(org == 0 && sweeped_cows.size() >= 1) {
            last_empty = time;
        }
        if(sweeped_cows.size() == 0) {
            tot += time - last_empty;
        }
    }

    int best = tot;
    for (int i = 0; i < n; i++) {
        best = min(best, ans[i]);
    }

    fout << tot - best << endl;

    return 0;
}