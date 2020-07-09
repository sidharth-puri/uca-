#include <iostream>
using namespace std;
int main()
{
	int l[]={2,1,3};
	int r[]={5,3,9};
	int i,max=0,count=0;
	for(i=0;i<3;i++)
	{
		if(r[i]>max)
		{
			max=r[i];
		}
	}
	int a[max+1];
	for(i=0;i<max+1;i++)
	{
		a[i]=0;
	}
	a[2]=1;
	a[6]=-1;
	a[1]=1;
	a[4]=-1;
	a[3]=1;
	a[10]=-1;
	int sum=a[0],index;
	for(i=1;i<max;i++)
	{
		a[i]=a[i]+a[i-1];
		if(sum<a[i])
		{
			sum=a[i];
			index=i;
		}
	}
	
	cout<<"MAX OCCURANCE = "<<index;
	return 0;
	
}
