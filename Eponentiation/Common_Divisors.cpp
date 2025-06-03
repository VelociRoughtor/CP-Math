#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, mx = INT_MIN; 
    cin >> n;
    vector<int> v(n), mp(1e6 + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        mx = max(mx, v[i]);
        mp[v[i]]++;
    }

    for (int i = mx; i >= 1; i--) {
        int cnt = 0;
        for (int j = i; j <= mx; j += i) {
            cnt += mp[j];
            if (cnt >= 2) {
                cout << i << endl;
                return;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}