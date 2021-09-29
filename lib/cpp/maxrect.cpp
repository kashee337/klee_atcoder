ll search_maxrect(vector<ll>& a) {
    a.push_back(0);
    int n = a.size();
    stack<pair<int, ll>> s;
    ll res = -1;
    rep(i, n) {
        if (s.empty()) {
            s.push({i, a[i]});
        } else {
            int prev_i = s.top().first;
            ll prev_a = s.top().second;
            if (prev_a < a[i]) {
                s.push({i, a[i]});
            } else if (prev_a > a[i]) {
                while (prev_a > a[i]) {
                    prev_i = s.top().first;
                    res = max(res, prev_a * (i - prev_i));
                    s.pop();
                    if (s.empty()) break;
                    prev_a = s.top().second;
                }

                if (!s.empty()) {
                    s.push({prev_i, a[i]});
                } else {
                    s.push({0, a[i]});
                }
            }
        }
    }
    a.pop_back();
    return res;
}