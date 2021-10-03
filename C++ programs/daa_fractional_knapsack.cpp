/*
Given two arrays weight[] and profit[] the weights and profit of N items, 
we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
*/

#include<bits/stdc++.h>
using namespace std;
void sort_end (double ratio[], int object[], int profit[], int weight[], int n)
{
	for (int i=0; i<n-1; i++)
	{
		int flag = 0;
		for (int j=0; j<n-1-i; j++)
		{
			if (ratio[j] < ratio[j+1])
			{
				swap(ratio[j], ratio[j+1]);
				swap(object[j], object[j+1]);
				swap(profit[j], profit[j+1]);
				swap(weight[j], weight[j+1]);
				flag = 1;
			}
		}
		if (flag == 0)
		break;
	}
//	for (int i=0; i<n; i++)
//	cout<<ratio[i]<<" ";
}
void fractional_knapsack(double ratio[], int object[], int profit[], int weight[], int n, int w)
{
	double max_profit = 0;
	int i = 0;
	while (w>0 && i<n)
	{
		if (weight[i] <= w)
		{
			max_profit += (double)profit[i];
			w -= weight[i];
		}
		else if (weight[i] > w)
		{
			max_profit +=  ((double)profit[i]*((double)w/(double)weight[i]));
			w = 0;
		}
		i++;
	}
	cout<<"\nMaximum profit: "<<max_profit<<endl;
}
int main()
{
	int n;
	cout<<"\nEnter size of array: ";
	cin>>n;
	int object[n], profit[n], weight[n];
	int w;
	cout<<"\nEnter profit array: ";
	for (int i=0; i<n; i++)
	cin>>profit[i];
	cout<<"\nEnter weight array: ";
	for (int i=0; i<n; i++)
	cin>>weight[i];
	cout<<"\nEnter knapsack capacity: ";
	cin>>w;
	for (int i=0; i<n; i++)
	object[i] = i+1;
	double ratio[n] = {0.0};
	for (int i=0; i<n; i++)
	ratio[i] = (double)profit[i]/(double)weight[i];
//	for (int i=0; i<n; i++)
//	cout<<ratio[i]<<" ";
	cout<<endl;
	sort_end(ratio, object, profit, weight, n);
	fractional_knapsack(ratio, object, profit, weight, n, w);
}

/*
Sample Input:
Enter size of array: 3
Enter profit array: 60 100 120
Enter weight array: 10 20 30
Enter knapsack capacity: 50

Sample Output: 
Maximum profit: 240
*/
