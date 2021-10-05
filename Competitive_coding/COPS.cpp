#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int M,x,y,t;
	cin>>t;
	while(t--)
	{
	    cin>>M>>x>>y;
	    int cops[101];
          for(int i=0;i<M;i++)
            cin>>cops[i];
            
        int dist=x*y;
        int count=0;
        for(int i=1;i<=100;i++)
        {
            bool safe=true;
            for(int j=0;j<M;j++)
            {
                int left=max(cops[j]-dist,1);
                int right=min(cops[j]+dist,100);
                if(i>=left && i<=right)  
                    safe=false;
            }
            if(safe) 
                count++;
        }
        cout<<count<<endl;
	    
	}
	return 0;
}
