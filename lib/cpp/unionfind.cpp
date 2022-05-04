struct UnionFind {
    vector<int> par;
    int group_num;
    UnionFind(int n) : par(n, -1), group_num(n) {}
    void init(int n) {
        par.assign(n, -1);
        group_num = n;
    }

    int root(int x) {
        if (par[x] < 0)
            return x;
        else
            return par[x] = root(par[x]);
    }

    bool issame(int x, int y) { return root(x) == root(y); }

    bool merge(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y);  // merge technique
        par[x] += par[y];
        par[y] = x;
        group_num--;
        return true;
    }

    int size(int x) { return -par[root(x)]; }

    int group_size() { return group_num; }
};