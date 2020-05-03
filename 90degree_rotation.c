#include<stdio.h>
int main()
{
	int a,i,j,temp;
	printf("size of an array");
	scanf("%d",&a);
	int **arr=(int **)malloc(sizeof(int)*a);
	for(i=0;i<a;i++)
	{
		*(arr+i)=(int *)malloc(sizeof(int)*a);
	}
	printf("enter array elements");
	for(i=0;i<a;i++)
	{
		for(j=0;j<a;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	for(i=0;i<a;i++)
	{
		for(j=0;j<a;j++)
		{
			if(i<j)
			{
				temp=arr[i][j];
				arr[i][j]=arr[j][i];
				arr[j][i]=temp;
			}
		}
	}
	for(i=0;i<a;i++)
	{
		for(j=0;j<a/2;j++)
		{
			temp=arr[i][j];
			arr[i][j]=arr[i][a-1-j];
			arr[i][a-1-j]=temp;			
		}
	}
	printf("array rotating after 90 degree\n");
	for(i=0;i<a;i++)
	{
		for(j=0;j<a;j++)
		{
	       printf("%d\t",arr[i][j]);		
		}
		printf("\n");
	}
}
