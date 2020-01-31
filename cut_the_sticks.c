int* cutSticks(int n, int *len, int *result_size) 
{
  int i,max=len[0],min,count,k=0,maxindex=0;
  int* arr=(int*)malloc(sizeof(int)*n);
  for(i=0;i<n;i++){
    if(len[i]>max){
      max=len[i];
      maxindex=i;
    }
  }
  while(len[maxindex]!=0){
    min=99999;
    for(i=0;i<n;i++){
      if(len[i]<min && len[i]!=0){
        min=len[i];
      }
    }
    count=0;
    for(i=0;i<n;i++){
      if(len[i]!=0){
        len[i]=len[i]-min;
        count++;
      }
    }
    arr[k]=count;
    k++;
  }
  *result_size=k;
  return arr;
}
int main(){
	int arr[100];
	int t;
	printf("enter size");
	scanf("%d",&t);
	int i;
	printf("\nenter elements\n");
	for(i=0;i<t;i++){
		scanf("%d",&arr[i]);
	}

	int size=0;
	int* a=cutSticks(t,arr,&size);
	for(i=0;i<size;i++){
		printf("%d ",a[i]);
	}
	return 0;
}
