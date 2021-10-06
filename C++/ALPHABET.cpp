#include <iostream>

using namespace std;

int main() {
    string s;
    bool charR[26] = {false};
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        charR[s[i] - 'a'] = true;
    }
    int t;
    cin >> t;
    while (t--) {
        bool canRead = true;
        string s1;
        cin >> s1;
        for (int i = 0; i < s1.length(); i++) {
            if (charR[s1[i] - 'a'] == false) {
                canRead = false;
                break;
            }
        }
        if (canRead) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}
//https://www.codechef.com/CUPP2101/problems/ALPHABET
