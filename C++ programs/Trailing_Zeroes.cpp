#include<iostream>
using namespace std;

int TrailingZeroes(int n)
{
  int ans = 0;
  for(int d = 5; n/d >= 1; d = d*5)
    {
      ans += n/d;
    }
  return ans;
}

int main(void)
{
  int n;
  cout<<"Enter The number "<<endl;
  cin>>n;
  cout<<"The number of trailing zeroes in factorial of "<<n<<" are "<<TrailingZeroes(n)<<endl;
}
