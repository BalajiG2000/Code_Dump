#include<iostream>
using namespace std;

void insertion_sort(int a[],int n)
{
    for(int i=1;i<n;i++)
    {
        int element =a[i];
        int j=i-1;
        while(j>=0 && element<a[j])
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1] = element;
    }
   
}


int main()
{
    int a[6] = {1,4,5,3,12,-3};
    int  n=6;

    insertion_sort(a,n);
    cout<<"Sorted Array is : "<<endl;

    for(int i=0;i<6;i++)
    {

        cout<<a[i]<<" ";
    }


    return 0;
}