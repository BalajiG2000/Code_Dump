// https://codeforces.com/problemset/problem/1579/B
// B. Shifting Sort



#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<pii> actions;
        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = 0; i < n - 1; i++) {
            int min_pos = i;
            for (int j = i + 1; j < n; j++)
                if (a[j] < a[min_pos])
                    min_pos = j;

            if (min_pos > i) {
                actions.push_back({i, min_pos});
                int opt = a[min_pos];
                for (int j = min_pos; j > i; j--)
                    a[j] = a[j - 1];
                a[i] = opt;
            }
        }

        cout << actions.size() << '\n';
        for (auto &lr: actions) {
            cout << lr.first + 1 << ' ' << lr.second + 1 << ' ' << lr.second - lr.first << '\n';
        }
    }

}
