#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;
int main()
{
    int t; cin>>t;
    while(t--)
    {
      int l; cin>>l;
      string s1;
      string s;
      char a[l];
      int cont1  = 0; int cont2 = 0;
      for(int x= 0 ; x < l; ++x)
      {
          cin>>a[x];
          if(a[x]=='.')
          {
              cont1++;
          }
          if(a[x] != '.')
          {
              s+=a[x];
          }
      }

      if(cont1 == l)
      {
          cout<<"Valid\n";
      }
      else{
         if(s.size() %2 !=0)
         {
             cout<<"Invalid\n";
         }
         else{
            int contsn = 0;
            for(int x = 0; x <s.size(); ++x)
            {
                if(s[x]=='H' && s[x+1]=='T')
                {
                    contsn++;
                }
            }

            if(contsn == s.size()/2)
            {
                cout<<"Valid\n";
            }
            else{
                cout<<"Invalid\n";
            }

         }//else2

      }//else

    }//while
    return 0;
}
