#include<stdio.h> 
struct Node 
{ 
	int data; 
	struct Node* next; 
}; 
struct Node *reverse (struct Node *head, int k) 
{ 
	struct Node* current = head; 
	struct Node* next = NULL; 
	struct Node* prev = NULL; 
	int count = 0; 
	while (current != NULL && count < k) 
	{ 
		next = current->next; 
		current->next = prev; 
		prev = current; 
		current = next; 
		count++; 
	} 
	if (next != NULL) 
	head->next = reverse(next, k); 
	return prev; 
} 
void push(struct Node** head_ref, int new_data) 
{ 
	struct Node* new_node = 
			(struct Node*) malloc(sizeof(struct Node)); 
	new_node->data = new_data; 
	new_node->next = (*head_ref);	 
	(*head_ref) = new_node; 
} 
void printList(struct Node *node) 
{ 
	while (node != NULL) 
	{ 
		printf("%d ", node->data); 
		node = node->next; 
	} 
}	 
int main(void) 
{ 
	struct Node* head = NULL;
	int n,i,a;
	printf("Enter the size");
	scanf("%d",&n);
	printf("Enter elements");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a);
		
			push(&head, a);
	 } 
	printf("\nGiven linked list \n"); 
	printList(head); 
	head = reverse(head, 3); 

	printf("\nReversed Linked list \n"); 
	printList(head); 

	return(0); 
} 

