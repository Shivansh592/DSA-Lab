#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node *NODE;

// Create a new node with given data
NODE createNodeInCLL(int data) {
    NODE temp = (NODE) malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Create CLL with n nodes
NODE createCLL(  int n     ) {
	if (n <= 0)
		return NULL;

	NODE first = NULL, temp, last=NULL;
int x;

for (int i = 1; i <= n; i++) {
    scanf("%d", &x);

    temp = createNodeInCLL(x);

    if (first == NULL) {
        first = temp;
		last = temp;
        last->next = first;
    } else {
        last->next = temp;
        temp->next = first;
        last = temp;
    }
}
return first; 
	


}

// Traverse CLL
void traverseListInCLL(  NODE first    ) {

// write your code here...
	NODE temp = first;

do {
    printf("%d -> ", temp->data);
    temp = temp->next;
} while (temp != first);

printf("\n");
	

}

// Insert at given position in CLL
NODE insertAtPositionInCLL(   NODE first, int pos, int x      ) {
	
//write your code here..
NODE temp = createNodeInCLL(x);

if (first == NULL && pos == 1) {
temp->next = temp;
		return temp;
	}

	int count = 1;
	NODE cur = first;
