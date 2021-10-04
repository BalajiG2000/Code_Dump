//linear search->

#include <iostream>
using namespace std;
int main()
{
    int i,n, num, index;
    cout<<"Enter the number of elements of the array:\n";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of array: \n";
    for(i=0; i<n; i++)
        cin>>arr[i];
    cout<<"\nEnter a Number to be Searched: ";
    cin>>num;
    for(i=0; i<n; i++)
    {
        if(arr[i]==num)
        {
            index = i;
            break;
        }
    }
    if(arr[i]==num)
    {
    cout<<"\nThe number "<<num<<" is found at Index No. :"<<index;
    cout<<endl;
    }
    else
    {
        cout<<"Element not found";
    }
    return 0;
}