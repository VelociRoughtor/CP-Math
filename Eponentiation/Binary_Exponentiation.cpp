#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll binExp(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

int main(){
    int x, n; 
    cin >> x >> n;
    cout << binExp(x, n) << endl;
    return 0;
}