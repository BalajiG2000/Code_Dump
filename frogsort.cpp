#include<bits/stdc++.h>
using namespace std;
int main()
{
     int t,N,temp,cnt,a,b,c,d,p,q,r,s;
    cin>>t;
    while(t--)
    {
        cin>>N;
         int w[N],l[N];
         cnt=0;
        for(int i=0;i<N;i++)
        {
            cin>>w[i];
        }
         for(int i=0;i<N;i++)
        {
            cin>>l[i];
        }
        if(N==2)
        {
        if(std::is_sorted(w,w+N))
            cnt=0;
        else if(l[0]==1)
            cout<<2<<endl ;
        else
            cout<<1<<endl;   
        }
        else if(N==3)
        {
            
            if(std::is_sorted(w,w+N))
            cnt = 0;
            else
            {
               for(int j=0;j<N;j++)
               {
               if(w[j]==1)
                a = p =j;
               else if(w[j]==2)
                b=q=j;
               else if(w[j]==3)
                c=r=j;
               }
               p=a;
               q=b;
               r=c;
                while(b<=a){
                b+=l[q];cnt++;}

                while(c<=b || c<=a){
                c+=l[r];cnt++;}
            }

        }
        else if(N==4)
        {
            
            if(std::is_sorted(w,w+N))
            cnt = 0;
            else
            {
               for(int j=0;j<N;j++)
               {
               if(w[j]==1)
                a=j;
                else if(w[j]==2)
                b=j;
               else if(w[j]==3)
                c=j;
               else if(w[j]==4)
                d=j;
               }
               p=a;
               q=b;
               r=c;
               s=d;
                while(b<=a){
                b+=l[q];cnt++;}

                while(c<=b || c<=a){
                c+=l[r];cnt++;}

                while(d<=a || d<=b || d<=c){
                d+=l[s];cnt++;}
            }

        }
        cout<<cnt<<endl;
        }  
    return 0;
}
