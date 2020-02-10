#include<stdio.h>
#include<string.h>
int* calculateZarray(char* str,int z[]) {
	int l=strlen(str);
	int i,left=0,right=0;
	for(i=1;i<l;i++) {
		if(i>right) {
			left=right=i;
			while(i<l && str[right]==str[right-left]) {
				right++;
			}
			z[i]=right-left;
			right--;
		}
		else {
			int k=i-left;
			if(z[k] < right-i+1) {
				z[i] = z[k];
			}
			else {
				left=i;
				while(i<l && str[right]==str[right-left]) {
					right++;
				}
				z[i]=right-left;
				right--;
			}
		}
	}
	return z;
}

int main(){
	char text[]="fuck fuck fuck fuck";
	char pattern[]="fuck";
	int textl=strlen(text);
	int patternl=strlen(pattern);
	char str[textl + patternl + 1];
	strcpy(str,pattern);
	strcat(str,"$");
	strcat(str,text);
	int zl=strlen(str);
	int z[zl];
	calculateZarray(str,z);
	int i;
	for(i=0;i<zl;i++) {
		if(z[i]==patternl){
			printf("%d ",i-patternl-1);
		}
	}
return 0;
}
