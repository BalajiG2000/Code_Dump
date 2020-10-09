// https://www.codechef.com/problems/MOVIEWKN

#include <iostream>
#include<vector>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int Larr[n];
        int Rarr[n];
         
        for(int i=0;i<n;i++)
        {
            cin>>Larr[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>Rarr[i];
        }

        int product[n];
        for(int i=0;i<n;i++)
        {
            product[i]=Larr[i]*Rarr[i];
        }

        int max;
        max=product[0];
        
        for(int i=1;i<n;i++)
        {
            if(product[i]>max)
                {
                    max=product[i];
                }
        }
        
        
        for(int i=1;i<n;i++)
        {
            if(product[i]!=max)
                {
                    product[i]=-1;
                }
        }
        
        int flag=-1;
        vector<int>a;
        for(int i=0;i<n;i++)
        {
            if(product[i]==max)
            {
                a.push_back(i);
            
            }
        }
        
        int largest;
        largest=Rarr[a[0]];
        for(int j=1;j<a.size();j++)
        {
            if(Rarr[a[j]]>largest)
            {
                largest=Rarr[a[j]];
            }
        }
        for(int i=0;i<n;i++)
        {
            if(largest==Rarr[i])
            {
                cout<<i+1<<endl;
                break;
            }
        }
    
        
    }
	
	return 0;
}
