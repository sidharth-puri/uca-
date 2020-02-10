#include <iostream>
using namespace std;
int main()
{
	int n,m;
	cout<<"Enter the size of rows \n";
	cin>>n;
	cout<<"Enter the size of cols \n";
	cin>>m;
	int a,b,c,d,i,count=0,j;
	a=0;
	b=m-1;
	c=n-1;
	d=0;
	int arr[n][m];
	while(a<=c && d<=b)
	{
		for(i=d;i<=b;i++)
		{
			arr[a][i]=count++;
		}
		a++;
		for(i=a;i<=c;i++)
		{
			arr[i][b]=count++;
		}
		b--;
		for(i=b;i>=d;i--)
		{
			arr[c][i]=count++;
		}
		c--;
		for(i=c;i>=a;i--)
		{
			arr[i][d]=count++;
		}
		d++;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<"\n";
	}
}
