#include<bits/stdc++.h>
using namespace std;

void swap(int arr[],int i,int j)
{
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

int partition(int arr[],int l,int r)
{
    int pivot=arr[r];
    int i=l-1;

    for(int j=l;j<r;j++)      //pivot se ek phle vale element tk run krega
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(arr,i,j);
        }
    }
    swap(arr,i+1,r);
    return i+1;                //i+1 becomes pivot
}

void quickSort(int arr[],int l,int r)
{
    if(l<r)
    {
        int pi=partition(arr,l,r);
        quickSort(arr,l,pi-1);
        quickSort(arr,pi+1,r);
    }
}

int main()
{
    int arr[7]={6,3,9,5,2,8,7};
    quickSort(arr,0,6);

    for(int i=0;i<7;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}