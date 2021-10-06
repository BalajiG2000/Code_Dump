#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll sum_n(ll n){
    return (n*(n+1)) / 2;
}

int main() {
	int t;
	cin >> t;
	while(t--){
	    ll n;
	    string s;
	    cin >> n >> s;
	    ll count_1 = count(s.begin(), s.end(), '1');
	    cout << sum_n(count_1) << endl;
	}
	return 0;
}
