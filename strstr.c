#include <stdio.h>
#include <strings.h>
int main()
{
	char str[100];
	char patt[100];
	int lps[100];
	gets(str);
	gets(patt);
	int i,j;
	for(j=1;j<strlen(patt);)
	{
		if(patt[i]==patt[j])
		{
			lps[j]=i+1;
			i++;
			j++;
		}
		else
		{
			if(i==0)
			{
				lps[j]=0;
				j++;
			}
			else
			{
				i=lps[i-1];
			}
		}
	}
	for(i=0;i<strlen(str);)
	{
		if(str[i]==patt[j])
		{
			i++;
			j++;
		}
		else
		{
			if(j==0)
			{
				i++;
			}
			else
			{
				j=lps[j-1];
			}
		}
	}
	if(j==strlen(patt))
	{
		printf("Pattern found");
	}
	else
	{
		printf("Not found");
	}
	return 0;
}
