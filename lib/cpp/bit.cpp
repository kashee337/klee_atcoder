template <typename T> struct BIT {
    // 1-indexed
  private:
    vector<T> dat;
    const T n;

  public:
    BIT(int _n) : dat(_n + 1, 0), n(_n) {}
    T sum(int i) {
        T s = 0;
        while (i > 0) {
            s += dat[i];
            i -= i & (-i);
        }
        return s;
    }
    T sum(int i, int j) {
        T val_i = sum(i - 1);
        T val_j = sum(j);
        return val_j - val_i;
    }
    void add(int i, T x) {
        while (i <= n) {
            dat[i] += x;
            i += i & (-i);
        }
    }
};