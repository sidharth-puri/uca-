#include <stdio.h>
#include <string.h>
int main()
{
	char str[100];
	gets(str);
	char** arr[100][100];
	int i=0;
	char* tok=strtok(str,".");
	
	strcpy(arr[i],tok);
	
	while(tok!=NULL)
	{
		i++;
		strcpy(arr[i],tok);
		
		tok=strtok(NULL,".");	
	}
	int j;
	for(j=0;j<i;j++)
	{
		printf("%s\n",arr[j]);
	}
	return 0;
}
