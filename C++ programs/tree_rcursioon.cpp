// Tree recursion is a type of recursion in which there is moe than one function call and recursion tracing is in form of  tree branches
#include<bits\stdc++.h>
using namespace std;
void fun(int n)
{
    if(n>0)
    {
        cout<<n<<" ";
        fun(n-1);
        fun(n-1);
    }
   
}
int main()
{
    cout<<"Enter the number: ";
    int y;
    cin>>y;
    cout<<"\n Output is : ";
    fun(y);
   return 0;
}