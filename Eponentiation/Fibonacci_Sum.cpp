#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000007

vector<vector<ll>> multiply(const vector<vector<ll>> &a, const vector<vector<ll>> &b, ll mod) {
    ll n = a.size(), m = b[0].size(), p = b.size();  
    vector<vector<ll>> res(n, vector<ll>(m, 0));
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            for (ll k = 0; k < p; k++) {
                res[i][j] = (res[i][j] + (a[i][k] * b[k][j]) % mod) % mod;
            }
        }
    }
    return res;
}

vector<vector<ll>> matrixExponentiation(vector<vector<ll>> a, ll k, ll mod) {
    ll n = a.size();
    vector<vector<ll>> res(n, vector<ll>(n, 0));
    for (ll i = 0; i < n; i++) res[i][i] = 1;
    while (k) {
        if (k & 1) res = multiply(res, a, mod);
        a = multiply(a, a, mod);
        k >>= 1;
    }
    return res;
}

ll kthFibonacciNumber(ll k) {
    if (k == 1) return 1;
    vector<vector<ll>> mat = {{1, 1}, {1, 0}};
    vector<vector<ll>> F = {{1}, {1}}; 
    vector<vector<ll>> res = matrixExponentiation(mat, k - 2, MOD); 
    res = multiply(res, F, MOD); 
    return res[0][0];
}

void solve() {
    ll n, m, sn = 0, sm = 0; cin >> n >> m;
    sn = kthFibonacciNumber(n + 1);
    sm = kthFibonacciNumber(m + 2);
    cout << (sm - sn + MOD) % MOD << endl;
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
