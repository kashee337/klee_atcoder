#include <algorithm>
#include <cmath>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define pb push_back
#define rep(i, n) for (int i = 0; i < (n); i++)
#define reps(i, n, s) for (int i = (s); i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define rreps(i, n, s) for (int i = s; i >= n; i--)

using ll = long long;
using namespace std;
constexpr long long MAX = 5100000;
constexpr long long INF = 1LL << 60;
constexpr int MOD = 1000000007;
struct edge {
    int to, cap, rev;
};
vector<bool> used;
vector<vector<edge>> G;
void add_edge(int from, int to, int cap) {
    G[from].push_back(edge{to, cap, (int)G[to].size()});
    G[to].push_back(edge{from, 0, (int)G[to].size() - 1});
}

int flow_dfs(int v, int t, int min_cap) {
    if (v == t) return min_cap;
    used[v] = true;
    for (edge& e : G[v]) {
        if (used[e.to]) continue;
        if (e.cap == 0) continue;
        int d = flow_dfs(e.to, t, min(min_cap, e.cap));
        if (d > 0) {
            e.cap -= d;
            G[e.to][e.rev].cap += d;
            return d;
        }
    }
    return 0;
}

int max_flow(int s, int t) {
    int flow = 0;
    while (true) {
        used.assign(used.size(), false);
        int f = flow_dfs(s, t, MAX);
        if (f == 0) return flow;
        flow += f;
    }
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int V, E;
    cin >> V >> E;
    G.assign(V, vector<edge>());
    used.assign(V, false);
    rep(i, E) {
        int u, v, c;
        cin >> u >> v >> c;
        add_edge(u, v, c);
    }
    cout << max_flow(0, V - 1) << endl;
    return 0;
}