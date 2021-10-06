#include <iostream>
using namespace std;
int main(){
	int a;
	cin >> a;
	while(a--){
		long b,c,d=0;
		cin >> b >> c;
		for (int i=2;i<=c;i++){
			if(d<b%i)
				d=b%i;
		}
		cout << d << endl;
	}
}
