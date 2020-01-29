#include <stdio.h>
int func(int *arr,int n,int mid)
{
	int sum=0,count=1,i;
	for(i=0;i<n;i++)
	{
		if(sum+arr[i]>mid)
		{
			count++;
			sum=arr[i];
		}
		else
		{
			sum+=arr[i];
		}
	}
	return count;
}
int main()
{
	int N,x;
	printf("Enter the number of books");
	scanf("%d",&N);
	int a[N],i;
	printf("Enter the pages");
	for(i=0;i<N;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter the number of students");
	scanf("%d",&x);
	int l=0,h=N-1,mid,stu;
	while(l<h)
	{
		 mid=(l+h)/2;
		 stu=func(a,N,mid);
		if(stu<=x)
		{
			h=mid;
		}
		else
		{
			l=mid+1;
		}
	}
	printf("%d",stu);
	
}
