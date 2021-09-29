#define CMAX 1010
int noinit = 1;
ll memo[CMAX][CMAX];
ll comb(ll a, ll b) {
    if (noinit) {
        rep(i, CMAX) rep(j, CMAX) memo[i][j] = -1;
        noinit = 0;
    }
    if (b == 0 || a == b) return 1;
    if (0 <= memo[a][b]) return memo[a][b];
    return memo[a][b] = comb(a - 1, b - 1) + comb(a - 1, b);
}