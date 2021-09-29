int get_lis(const vector<int>& a) {
    int res = 1;
    vector<int> dp(a.size(), MAX);
    for (int v : a) {
        int idx = upper_bound(dp.begin(), dp.end(), v) - dp.begin();
        dp[idx] = v;
        res = max(res, idx + 1);
    }
    return res;
}