ll calc_gcd(ll x, ll y) {
    if (y == 0) return x;
    return calc_gcd(y, x % y);
}

ll calc_lcm(ll x, ll y) { return (x / calc_gcd(y, x % y)) * y; }
