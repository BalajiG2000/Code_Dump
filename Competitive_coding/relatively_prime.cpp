#include <bits/stdc++.h>
using namespace std;
#define Max 1000000
bool prime[Max];


int main()
{
    
    long long int l, r;
    cin >> l >> r;
    if( (l-r+1)%2!=0 ) 
    cout<<"NO\n";
    else
    {
        cout<<"YES\n";
        for( long long int i=l;i<=r;i+=2)
        {
            cout<<i<<" "<<i+1<<endl;
        }
    }

}