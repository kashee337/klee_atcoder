struct Zeta2D {
    vector<vector<ll>> _mat;
    ll N1, N2;
    Zeta2D(ll _N1, ll _N2) {
        N1 = _N1;
        N2 = _N2;
        _mat.resize(_N1 + 1, vector<ll>(_N2 + 1, 0));
    }
    void init(ll _N1, ll _N2) {
        N1 = _N1;
        N2 = _N2;
        _mat.resize(_N1 + 1, vector<ll>(_N2 + 1, 0));
    }

    void add(ll x, ll y, ll v) { _mat[y + 1][x + 1] = v; }
    void build() {
        rep(i, N1 + 1) {
            rep(j, N2) { _mat[i][j + 1] += _mat[i][j]; }
        }
        rep(i, N1) {
            rep(j, N2 + 1) { _mat[i + 1][j] += _mat[i][j]; }
        }
    }
    ll get(ll x, ll y) { return _mat[y + 1][x + 1]; }

    ll get_rect(ll x1, ll y1, ll x2, ll y2) {
        ll v = _mat[y2][x2] - _mat[y2][x1] - _mat[y1][x2] + _mat[y1][x1];
        return v;
    }
};