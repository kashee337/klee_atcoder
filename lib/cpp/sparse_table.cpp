template <typename T> struct SparseTable {
    vector<vector<T>> st;
    vector<int> lookup;
    SparseTable(const vector<T>& v) {
        int n = v.size();
        int k = 0;
        while ((1 << k) <= v.size()) k++;
        st.assign(k, vector<T>(1 << k));
        for (int i = 0; i < n; i++) st[0][i] = v[i];
        for (int i = 1; i < k; i++) {
            for (int j = 0; j + (1 << i) <= (1 << k); j++) {
                st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            }
        }
        lookup.resize(n + 1);
        for (int i = 2; i < lookup.size(); i++) { lookup[i] = lookup[i >> 1] + 1; }
    }

    T query(int l, int r) {
        int k = lookup[r - l];
        return min(st[k][l], st[k][r - (1 << k)]);
    }
};
