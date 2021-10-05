#include<bits/stdc++.h>
#define ll long long
#define lld long long int
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define frInt(x,n) for(int i=x;i<n;i++)
#define frLld(x,n) for(lld i=x;i<n;i++)
#define all(v) v.begin(),v.end()
#define maxt(a,b,c) max(a,max(b,c))
#define mint(a,b,c) min(a,min(b,c))
#define rsort(v) sort(v.rbegin(),v.rend())
#define pb push_back
#define printarr(a,n) for(int i=0;i<n;i++)cout<<a[i]<<" ";cout<<"\n";
using namespace std;
int main(){
    fastio;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        frInt(0,n)cin>>arr[i];
        int f=1,head=0,tail=n-1;
        if(arr[0]!=1 && arr[n-1]!=1){
            cout<<"no\n";
            continue;
        }
        while(head<tail){
            if(arr[head]!=arr[tail]){
                f=0;
                break;
            }
            else if(arr[head]!=arr[head+1] && arr[head+1]!=arr[head]+1){
                f=0;
                //cout<<"s";
                break;
            }
            head++;tail--;
        }
        if(arr[head]==7 && f==1)
            cout<<"yes\n";
        else
            cout<<"no\n";
    }
    return 0;
}
