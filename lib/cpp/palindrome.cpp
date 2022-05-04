vector<ll> manacher(const string& _s) {
    int n = _s.length(), i, j;
    string s(2 * n + 1, '#');
    for (i = 0; i < n; i++) s[2 * i + 1] = _s[i];
    n = 2 * n + 1;

    vector<ll> rad(n);
    for (i = j = 0; i < n;) {
        while (0 <= i - j && i + j < n && s[i - j] == s[i + j]) j++;
        rad[i] = j;

        int k;
        for (k = 1; i - k >= 0 && rad[i - k] < rad[i] - k; k++) rad[i + k] = rad[i - k];

        i += k;
        j = max(j - k, 0);
    }
    return rad;
}

ll get_maxLenPalindrome(const string& s) {
    vector<ll> rad = manacher(s);
    return *max_element(rad.begin(), rad.end()) - 1;
}

ll get_numPalindrome(const string& s) {
    vector<ll> rad = manacher(s);
    int n = s.length() * 2 + 1;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0)
            rad[i] = (rad[i] - 1) / 2;
        else
            rad[i] /= 2;
    }
    return accumulate(rad.begin(), rad.end(), 0);
}
string get_manacher(const string& _s) {
    int n = _s.length(), i, j;
    string s(2 * n + 1, '#');
    for (i = 0; i < n; i++) s[2 * i + 1] = _s[i];
    n = 2 * n + 1;

    vector<ll> rad(n);
    for (i = j = 0; i < n;) {
        while (0 <= i - j && i + j < n && s[i - j] == s[i + j]) j++;
        rad[i] = j;
        int k;
        for (k = 1; i - k >= 0 && rad[i - k] < rad[i] - k; k++) rad[i + k] = rad[i - k];

        i += k;
        j = max(j - k, 0);
    }
    int idx = max_element(rad.begin(), rad.end()) - rad.begin();
    string tmp = "";
    tmp += s[idx];
    rep(i, rad[idx] - 1) { tmp = s[idx + i + 1] + tmp + s[idx + i + 1]; }
    string res = "";
    for (char c : tmp)
        if (c != '#') res += c;
    return res;