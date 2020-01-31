#include <iostream>
using namespace std;
int main()
{
	int size;
	cout<<"Enter size of array \n";
	cin>>size;
	int arr[size];
	int i,n,count=1;
	for(i=0;i<size;i++)
	{
		arr[i]=count;
		count++;
	}
	cout<<"Enter the number of rotations \n";
	cin>>n;
	int t=n%size;
	int temp,j;
	for(j=0;j<t;j++)
	{
	
	temp=arr[size-1];
  for(i = size-1; i > 0; i--)
  {      
    arr[i] = arr[i-1];
  }
    arr[0]=temp;
}
	for(i=0;i<size;i++)
	{
		cout<<arr[i];
	}
}
