#include<bits/stdc++.h>
using namespace std;

#define ll long long 

ll fastMultiplication(ll a, ll b, ll mod) {
    ll res = 0;
    a = a % mod;
    while (b > 0) {
        if (b & 1) res = (res + a) % mod;
        a = (a * 2) % mod;
        b >>= 1;
    }
    return res;
}

void solve() {
    ll a, b, c; cin >> a >> b >> c;
    cout << fastMultiplication(a, b, c) << endl;
}

int main(){
    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

