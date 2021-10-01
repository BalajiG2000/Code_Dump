#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the size if the array:";
    cin>>n;
    int arr[n];
    cout<<"Enter the array:";
    for(int i=0;i<=n;i++)
    {
        cin>>arr[i];
    }
    cout<<endl;
   int sum=0;
   for(int i=0;i<n;i++)
   {  sum=0;
       for(int j=i;j<n;j++)
       {
           sum=sum+arr[j];
           cout<< sum<<endl;
       }
       cout<<endl<<endl;
   }
    return(0);
}