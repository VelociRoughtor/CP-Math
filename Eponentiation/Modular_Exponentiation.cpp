// Find a ^ b ^ c.

#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll MOD = 1e9 + 7;

ll binExp(ll a, ll b, ll mod) {
    ll res = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

void solve() {
    ll a, b, c, exp, res;
    cin >> a >> b >> c;
    exp = binExp(b, c, MOD - 1);
    cout << binExp(a, exp, MOD) << endl;
}

int main(){
    int t; 
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}