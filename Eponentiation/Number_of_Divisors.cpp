#include<bits/stdc++.h>
using namespace std;

#define ll long long

const ll N = 1e6 + 5;
ll spf[N];

void SPF() {
    for (ll i = 2; i < N; i++) {
        spf[i] = i;
    }

    for (ll i = 2; i * i < N; i++) {
        if (spf[i] == i) {
            for (ll j = i * i; j < N; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }    
}

void solve() {
    ll x; 
    cin >> x;
    map<ll, ll> primeFactors;
    while (x > 1) {
        primeFactors[spf[x]]++;
        x /= spf[x];
    }

    ll res = 1;
    for (auto &[f, s] : primeFactors) {
        res *= (s + 1);
    }

    cout << res << endl;
}

int main(){
    SPF(); 
    ll t;
    cin >> t;
    while(t--) {
        solve();
    }
    
    return 0;
}