#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void reverse(int a[], int l, int h)
{
    while (l <= h)
    {
        swap(a[l], a[h]);
        l++;
        h--;
    }
}
int main()
{
    //enter the number
    ll n;
    cin >> n;
    ll temp = n;
    int a[32];
    memset(a, -1, sizeof(a));
    int k = 31;
    while (n > 0)
    {
        if (k < 0)
        {
            break;
        }
        a[k] = n % 10;
        n = n / 10;
        k--;
    }

for( int i=0;i<32;i++)
cout<<a[i]<<" ";

cout<<endl;

    int bit = -1, index_of_bit;
    //array a containg our number digit
    //1. finding the bit where dip took place
    for (int i = 30; i >= 0; i--)
    {
        if (a[i] == -1)
        {
            break;
        }
        if (a[i] < a[i + 1])
        {
            bit = a[i];
            index_of_bit = i;
            break;
        }
    }
    if (bit == -1)
    {
        cout<< -1;
    }
    //2.swaping the bit and slightly greater element
    long long minmsb = INT_MAX, index_of_minmsb;
    for (int i = 31; i > index_of_bit; i--)
    {
        if (a[i] > bit && a[i] < minmsb)
        {
            minmsb = a[i];
            index_of_minmsb = i;
        }
    }
    swap(a[index_of_minmsb], a[index_of_bit]);


    for( int i=0;i<32;i++)
cout<<a[i]<<" ";
cout<<endl;


    //3.reverse the array
    reverse(a, index_of_bit + 1, 31);


     for( int i=0;i<32;i++)
cout<<a[i]<<" ";
cout<<endl;


    //4 using stringbuilder
    std::stringstream ss;
    for (int i = 0; i < 32; i++)
    {
        if (a[i] != -1)
            ss << a[i];
    }
    int ansl;
    ss >> ansl;

    cout<< ansl;
    
}
