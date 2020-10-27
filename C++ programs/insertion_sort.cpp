/*
  * Insertion sort is a kind of sorting algorithm
  * which sorts the elements in O(n^2) time.
  * First step is to iterate over the elements 
  * Next compare if the element is smaller than key or not
  * If yes then swap the element with it's suitable position
  * If no then keep iterating over the elements
*/

#include <iostream>
using namespace std;

// Function to sort an array using insertion sort algorithm
void insertionSort(int arr[], int n)
{
    int i, key, j;  
    for (i = 1; i < n; i++) 
    {  
        key = arr[i];  
        j = i - 1;  
  
        /* Move elements of arr[0..i-1], that are  
        greater than key, to one position ahead  
        of their current position */
        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
    }  
}

int main()
{
  int n;  // accepts the number of elements
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++)  // accepts the elements of array
  cin>>a[i];
  insertionSort(a,n); // function call
  for(int i=0;i<n;i++)  // print the sorted elements
  cout<<a[i]<<" ";
  return 0;
}
