
inline ll mod(ll a, ll m) { return (a % m + m) % m; }

ll extGcd(ll a, ll b, ll& p, ll& q) {
    if (b == 0) {
        p = 1;
        q = 0;
        return a;
    }
    ll d = extGcd(b, a % b, q, p);
    q -= a / b * p;
    return d;
}

pair<ll, ll> crt(const vector<ll>& b, const vector<ll>& m) {
    ll r = 0, M = 1;
    for (int i = 0; i < (int)b.size(); ++i) {
        ll p, q;
        ll d = extGcd(M, m[i], p, q);  // p is inv of M/d (mod. m[i]/d)
        if ((b[i] - r) % d != 0) return make_pair(0, -1);
        ll tmp = (b[i] - r) / d * p % (m[i] / d);
        r += M * tmp;
        M *= m[i] / d;
    }
    return make_pair(mod(r, M), M);
}
