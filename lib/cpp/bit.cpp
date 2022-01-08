template <typename T> struct BIT {
    // 1-indexed
  private:
    vector<T> dat;
    const T n;

  public:
    BIT(int _n) : dat(_n + 5, 0), n(_n) {}
    T sum(int i, int j) {
        if (i > j) return 0;
        return _sum(j) - _sum(i - 1);
    }

    T _sum(int i) {
        i++;
        T res = 0;
        while (i > 0) {
            res += dat[i];
            i -= i & (-i);
        }
        return res;
    }
    void add(int i, T x) {
        i++;
        while (i <= n) {
            dat[i] += x;
            i += i & (-i);
        }
    }
    T k_th_num(int k) {
        T l = 0, r = n;
        while (l + 1 < r) {
            T m = (l + r) / 2;
            T v = sum(m, n - 1);
            if (v < k)
                r = m;
            else
                l = m;
        }
        return r;
    }
};