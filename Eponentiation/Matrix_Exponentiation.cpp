#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000007

vector<vector<ll>> multiply(const vector<vector<ll>> &a, const vector<vector<ll>> &b, ll mod) {
    ll n = a.size();
    vector<vector<ll>> res(n, vector<ll>(n, 0));
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            for (ll k = 0; k < n; k++) {
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

int main() {
    ll n, k;
    cin >> n >> k;
    vector<vector<ll>> mat(n, vector<ll>(n));
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    vector<vector<ll>> res = matrixExponentiation(mat, k, MOD);

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
