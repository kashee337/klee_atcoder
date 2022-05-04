struct LCA {
  private:
    vector<vector<int>> parents;
    vector<int> depth;
    void init(vector<vector<int>>& g) {
        int N = g.size();
        int K = 1;
        while ((1 << K) < N) K++;
        parents.assign(K, vector<int>(N, -1));
        depth.assign(N, 0);
        dfs(g, 0, -1, 0);
        for (int k = 0; k + 1 < K; k++) {
            for (int i = 0; i < N; i++) {
                if (parents[k][i] != -1) { parents[k + 1][i] = parents[k][parents[k][i]]; }
            }
        }
    }
    void dfs(vector<vector<int>>& g, int crr, int from, int d) {
        parents[0][crr] = from;
        depth[crr] = d;
        for (int to : g[crr]) {
            if (to == from) continue;
            dfs(g, to, crr, d + 1);
        }
    }

  public:
    LCA(vector<vector<int>>& g) { init(g); }

    int query(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        int K = parents.size();
        for (int k = 0; k < K; k++) {
            if (((depth[u] - depth[v]) >> k) & 1) { u = parents[k][u]; }
        }
        if (u == v) return u;
        for (int k = K - 1; k >= 0; k--) {
            if (parents[k][u] != parents[k][v]) {
                u = parents[k][u];
                v = parents[k][v];
            }
        }
        return parents[0][u];
    }

    int path_length(int u, int v) { return depth[u] + depth[v] - 2 * depth[query(u, v)]; }

    bool is_on_path(int u, int v, int a) { return path_length(u, a) + path_length(a, v) == path_length(u, v); }
};