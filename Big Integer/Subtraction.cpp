#include <bits/stdc++.h>
using namespace std;

string sub(string a, string b) {
    char sign = '+';
    if (a.size() < b.size() || (a.size() == b.size() && a < b)) {
        swap(a, b);
        sign = '-';
    }

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    
    string c = "";
    int bor = 0;
    for (int i = 0; i < a.size(); i++) {
        int x = a[i] - '0';
        int y = (i < b.size()) ? b[i] - '0' : 0;
        
        int res = x - y - bor;
        if (res < 0) {
            res += 10;
            bor = 1;
        } else {
            bor = 0;
        }
        c.push_back(res + '0');
    }

    while (c.size() > 1 && c.back() == '0') {
        c.pop_back();
    }

    if (sign == '-') c.push_back('-');
    reverse(c.begin(), c.end());
    return c;
}

void solve() {
    string a, b;
    cin >> a >> b;
    cout << sub(a, b) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
