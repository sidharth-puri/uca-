#include <stdio.h>


int main(void) {
    long long int n,w,l,i;
	scanf("%lld%lld%lld",&n,&w,&l);
	long long int h[n],r[n];
	for(i=0;i<n;i++)
	{
	    scanf("%lld",&h[i]);
	    scanf("%lld",&r[i]);
	}
	long long int sum=0;
	long long int left=0;
	long long int right=1000000000000000000;
	while(left<right)
	{
	    sum=0;
	   long long int mid=(left+right)/2;
	    for(i=0;i<n;i++)
	    {
	        
	        if(h[i]+r[i]*mid>=l)
	        {
	            sum=sum+h[i]+r[i]*mid;
	            if(sum>=w)
	            {
	               break;
	            }
	        }
	    }
	    if(sum>=w)
	    {
	    right=mid;
	    }
	    else
	    {
	    left=mid+1;
	    }
	    
	    
	}
	printf("%lld",right);
	return 0;
}


