#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char** split_string(char*);

struct Node
{
    int data;
    struct Node* next; 
};
struct Node* newnode(int data)
{
    struct Node* new=(struct Node*)malloc(sizeof(struct Node));
    new->data=data;
    new->next=NULL;
    return new;
}
int isEmpty(struct Node* top)
{
    return !top;
}
void push(struct Node** top,int data)
{
    struct Node* newtop=newnode(data);
    newtop->next=*top;
    *top=newtop;

    
}
void pop(struct Node** top)
{
    /*if(isEmpty(*top))
    {
        return INT_MIN;
    }*/
    struct Node* temp=*top;
    (*top)=(*top)->next;
    int val=temp->data;
    free(temp);

   // return val;
}
int peek(struct Node* top)
{
   if(isEmpty(top))
   {
       return INT_MIN;
   }
   return top->data;
}

int* waiter(int number_count, int* number, int q, int* result_count) {
       int n=10000000;
       bool prime[n+1]; 

    memset(prime, true, sizeof(prime)); 
  int p,i;
    for ( p=2; p*p<=n; p++) 
    { 
         
        if (prime[p] == true) 
        { 
                    for ( i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
    struct Node* A=NULL;
     struct Node* A2=NULL;
    struct Node* B=NULL;
    
    for(i=0;i<number_count;i)
    {
     push(&A,number[i]);
    }
    i=0;
    while(i<q)
    {
        
        while(!isEmpty(A))
        {
        if(peek(A)%prime[i]==0)
        {
            push(&B,peek(A));
        }
        else
        {
            push(&A2,peek(A));
        }
        pop(&A);
        }
        A=A2;

        i++;
    }
    int k=0;
    
        while(!isEmpty(B))
        {
            number[k]=peek(B);
            pop(&B);
            k++;
        }
    
    *result_count=k;
    return number;


}























             
int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char** nq = split_string(readline());

    char* n_endptr;
    char* n_str = nq[0];
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    char* q_endptr;
    char* q_str = nq[1];
    int q = strtol(q_str, &q_endptr, 10);

    if (q_endptr == q_str || *q_endptr != '\0') { exit(EXIT_FAILURE); }

    char** number_temp = split_string(readline());

    int number[n];
int number_itr;
    for (number_itr=0; number_itr < n; number_itr++) {
        char* number_item_endptr;
        char* number_item_str = number_temp[number_itr];
        int number_item = strtol(number_item_str, &number_item_endptr, 10);

        if (number_item_endptr == number_item_str || *number_item_endptr != '\0') { exit(EXIT_FAILURE); }

        number[number_itr] = number_item;
    }

    int result_count;
    int* result = waiter(n, number, q, &result_count);
int result_itr;
    for (result_itr=0; result_itr < result_count; result_itr++) {
        fprintf(fptr, "%d", result[result_itr]);

        if (result_itr != result_count - 1) {
            fprintf(fptr, "\n");
        }
    }

    fprintf(fptr, "\n");

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);
        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}

