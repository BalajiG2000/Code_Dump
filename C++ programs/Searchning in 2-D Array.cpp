//Searchning in 2-D Array

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,i,j;
    cin>>n>>m;
    int arr[n][m];
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }
    
    int s;
    cin>>s;
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
          if(s==arr[i][j])
          {
            break;  
          }
        }
        if(s==arr[i][j])
          {
            break;  
          }
    }
    
    if(s==arr[i][j])
          {
            cout<<"number found at index :"<<i<<" "<<j;  
          }
    else
    {
        cout<<"no such number present";
    }
    return 0;
}
