struct MaxLazySegTree {
  private:
    int n;
    vector<ll> node, lazy;

  public:
    MaxLazySegTree(vector<ll>& v) {
        int m = v.size();
        n = 1;
        while (n < m) n *= 2;
        node.resize(2 * n + 1);
        lazy.resize(2 * n + 1, 0);
        for (int i = 0; i < m; i++) node[i + n] = v[i];
        for (int i = n - 1; i > 0; i--) node[i] = max(node[i * 2], node[i * 2 + 1]);
    }

    void eval(int k, int l, int r) {
        if (lazy[k] != 0) {
            node[k] = lazy[k];

            if (r - l > 1) {
                lazy[2 * k] = lazy[k];
                lazy[2 * k + 1] = lazy[k];
            }
            lazy[k] = 0;
        }
    }
    void update(int a, int b, ll x, int k = 1, int l = 0, int r = -1) {
        if (r < 0) r = n;
        eval(k, l, r);

        if (b <= l || r <= a) return;
        if (a <= l && r <= b) {
            lazy[k] = x;
            eval(k, l, r);
        } else {
            update(a, b, x, 2 * k, l, (l + r) / 2);
            update(a, b, x, 2 * k + 1, (l + r) / 2, r);
            node[k] = max(node[2 * k], node[2 * k + 1]);
        }
    }
    // [a,b)
    ll getmax(int a, int b, int k = 1, int l = 0, int r = -1) {
        if (r < 0) r = n + 1;
        if (b <= l || r <= a) return 0;
        eval(k, l, r);

        if (a <= l && r <= b) {
            return node[k];
        } else {
            ll vl = getmax(a, b, 2 * k, l, (l + r) / 2);
            ll vr = getmax(a, b, 2 * k + 1, (l + r) / 2, r);
            return max(vl, vr);
        }
    }
};