struct AddLazySegTree {
  private:
    int n;
    vector<ll> node, lazy;

  public:
    AddLazySegTree(vector<ll>& v) {
        int m = v.size();
        n = 1;
        while (n < m) n *= 2;
        node.resize(2 * n + 1);
        lazy.resize(2 * n + 1, 0);
        for (int i = 0; i < m; i++) node[i + n] = v[i];
        for (int i = n - 1; i > 0; i--) node[i] = node[i * 2] + node[i * 2 + 1];
    }

    void eval(int k, int l, int r) {
        if (lazy[k] != 0) {
            node[k] += lazy[k];

            if (r - l > 1) {
                lazy[2 * k] += lazy[k] / 2;
                lazy[2 * k + 1] += lazy[k] / 2;
            }
            lazy[k] = 0;
        }
    }
    void add(int a, int b, ll x, int k = 1, int l = 0, int r = -1) {
        if (r < 0) r = n;
        eval(k, l, r);

        if (b <= l || r <= a) return;
        if (a <= l && r < b) {
            lazy[k] += (r - l) * x;
            eval(k, l, r);
        } else {
            add(a, b, x, 2 * k, l, (l + r) / 2);
            add(a, b, x, 2 * k + 1, (l + r) / 2, r);
            node[k] = node[2 * k] + node[2 * k + 1];
        }
    }

    // [a,b)
    ll getsum(int a, int b, int k = 1, int l = 0, int r = -1) {
        if (r < 0) r = n + 1;
        if (b <= l || r <= a) return 0;
        eval(k, l, r);

        if (a <= l && r <= b) {
            return node[k];
        } else {
            ll vl = getsum(a, b, 2 * k, l, (l + r) / 2);
            ll vr = getsum(a, b, 2 * k + 1, (l + r) / 2, r);
            return vl + vr;
        }
    }
};
