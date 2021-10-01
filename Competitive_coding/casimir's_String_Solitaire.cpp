// Codeforces Round #744 (Div. 3)
// Problem-A. Casimir's String Solitaire
// https://codeforces.com/contest/1579/problem/A


#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << (count(s.begin(), s.end(), 'B') * 2 == s.size() ?
                 "YES\n" : "NO\n");
    }
}
