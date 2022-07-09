/*
https://cses.fi/problemset/task/1679/

this is like a graph problem that feels like some altered version of bfs
my first idea was to somehow get the courses that can be immediatly be completed and complete them
we can store the entire graph as nodes (courses) with directed edges where i can from one node to another when the other node depends on me
this leaves the obvious issue which is how to handle it so that courses are only usable when all pre-reqs are completed
now i looked at mspaint and thought about it for a bit
let's say first off we get all the immediatly usable courses and put it in our bfs
now we greedily solve all of them
here i came to the realization that a course will always and only be immediatly usable once the last pre-req has been completed
so now that i have realized this, we can simply keep the # of pre-reqs left in each node
once this reaches 0, we add it to the queue

formally:
make a directed graph with nodes such that for each edge a b, a -> b
for every edge a b, increment b's pre-req counter in a vector p
take all nodes i with p[i] == 0 and add them to a queue
bfs on these nodes:
    let curr_node = c
    add c to path
    for each adjacent node e to c, decrement p[e] by 1
    if p[e] == 0, add it to the queue
check for all nodes i if p[i] == 0
if it is, the answer is yes, if not it is not possible
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

ll n, m;

int main() {
    cin >> n >> m;

    vi p(n);
    vector<set<int>> adj(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;

        if (adj[a].find(b) == adj[a].end()) {
            adj[a].insert(b);
            p[b]++;
        }
    }

    queue<int> q;

    for (int i = 0; i < n; i++) {
        if (p[i] == 0) q.push(i);
    }

    vector<int> path;

    while (!q.empty()) {
        int top = q.front();
        q.pop();

        path.push_back(top);

        for (int child : adj[top]) {
            p[child]--;

            if (p[child] == 0) q.push(child);
        }
    }

    for (int i = 0; i < n; i++) {
        if (p[i] != 0) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    for (int i : path) cout << i + 1 << " ";
    cout << endl;

    return 0;
}