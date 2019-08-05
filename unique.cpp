#include <iostream>
using namespace std;
int main()
{
	int n;
	cout<<"Enter the size of array \n";
	cin>>n;
	int arr[n],i;
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int j=0;
	for(i=0;i<n;i++)
	{
		if(arr[i]==arr[j])
		{
			continue;
		}
		if(arr[i]!=arr[j])
		{
			j++;
			arr[j]=arr[i];
		}
	}
	for(i=0;i<=j;i++)
	{
		cout<<arr[i];
	}
}
