#include<bits/stdc++.h>
using namespace std;

string sum(string &a, string &b) {
    string c = "";
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int car = 0, n = a.size(), m = b.size();
    for (int i = 0; i < max(n, m); i++) {
        int x = (i < n) ? a[i] - '0' : 0;
        int y = (i < m) ? b[i] - '0' : 0;
        int s = x + y + car;
        c.push_back(s % 10 + '0');
        car = s / 10;
    }
    if (car) c.push_back(car + '0');
    reverse(c.begin(), c.end());
    return c;
}

void solve() {
    string a, b; 
    cin >> a >> b;
    cout << sum(a, b) << endl;
}

int main(){
    int t; 
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}