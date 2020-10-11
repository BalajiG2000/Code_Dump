//https://codeforces.com/contest/1370/problem/C


#include <bits/stdc++.h>
using namespace std;
int prime(int x){
    int f=1;
    for(int i=2;i<=sqrt(x);i++){
        if(x%i==0){
            f=0;
            break;
        }
    }
    return f;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    if(n%2!=0 &&n!=1){
	        cout<<"Ashishgup\n";
	    }
	    else if(n==1)
	        cout<<"FastestFinger\n";
	    else if(n==2)
	        cout<<"Ashishgup\n";
	    else{
	        if((n & (n-1))==0)
	            cout<<"FastestFinger\n";
	        else{
	            if(n%4==0)
	                cout<<"Ashishgup\n";
	            else{
	                if(prime(n/2)==1)
	                    cout<<"FastestFinger\n";
	                else
	                cout<<"Ashishgup\n";
	            }
	        }
	    }
	}
	return 0;
}