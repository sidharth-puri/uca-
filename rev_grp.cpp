#include <iostream>
using namespace std;
int main()
{
	int n,i,j;
	cout<<"Enter the size of array\n";
	cin>>n;
	int a[n];
	int k;
	cout<<"Enter the size of group\n";
	cin>>k;
	int l=n%k;
	cout<<"Enter the elements\n";
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(i=0;i<n;i=i+k)
	{
		if(i+k<=n)
		{
			for(j=0;j<k/2;j++)
			{
				swap(a[i+j],a[i+k-1-j]);
			}
		}
		else
		{
			for(j=0;j<l/2;j++)
			{
				swap(a[i+j],a[i+l-1-j]);
			}
		}
	}
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	
}
