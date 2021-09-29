map<ll, ll> get_prime(ll n) {
    map<ll, ll> prime;
    ll num = n;
    for (ll i = 2; i * i <= n; i++) {
        while (num % i == 0) {
            prime[i]++;
            num /= i;
        }
    }
    if (num > 1) prime[num]++;

    return prime;
}