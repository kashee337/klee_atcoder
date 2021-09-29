template <typename T>
vector<T> factorize(T n) {
  vector<T> res;
  for (ll i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      res.pb(i);
      if (i != n / i) {
        res.pb(n / i);
      }
    }
  }
  sort(res.begin(), res.end());
  return res;
}