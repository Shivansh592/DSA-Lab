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

	do {
		count++;
		cur = cur->next;
	} while (cur != first);

	if (pos < 1 || pos > count) {
		printf("Position not found\n");
		return first;
	}
if (pos == 1) {
		NODE last = first;
		while (last->next != first)
			last = last->next;

		temp->next = first;
		last->next = temp;
		first = temp;
	} else {
		NODE prev = first;
		for (int i = 1; i < pos - 1; i++)
			prev = prev->next;

		temp->next = prev->next;
		prev->next = temp;
	}

	return first;

 
    


 

	
}

// Delete node at given position in CLL
NODE deleteAtPositionInCLL(   NODE first, int pos    ) {
if (first == NULL) {
		printf("CLL is empty\n");
		return first;
	}

	int count = 1;
	NODE temp = first;
	while (temp->next != first) {
		count++;
		temp = temp->next;
	}

	if (pos < 1 || pos > count) {
		printf("Position not found\n");
		return first;
	}

	if (pos == 1) {
		NODE last = first;
		while (last->next != first)
			last = last->next;

		NODE del = first;

		if (first->next == first) {
			printf("Deleted element: %d\n", del->data);
			free(del);
			return NULL;
		}

		first = first->next;
		last->next = first;
		printf("Deleted element: %d\n", del->data);
		free(del);
	} else {
		NODE prev = first;
		for (int i = 1; i < pos - 1; i++)
			prev = prev->next;

		NODE del = prev->next;
		prev->next = del->next;
		printf("Deleted element: %d\n", del->data);
		free(del);
	}

	return first;


	
	
}

// Reverse CLL
NODE reverseCLL(    NODE first    ) {
	
//write your code here...
NODE prev = NULL, current = first, next = NULL;
	NODE last = first;

	if (first == NULL || first->next == first)
		return first;

	do {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	} while (current != first);

	first->next = prev;
	first = prev;

	return first;
	

}

// Concatenate two CLLs
NODE concatCLL(    NODE first, NODE second       ) {

if (first == NULL)
		return second;
	if (second == NULL)
		return first;

	NODE temp1 = first;
	while (temp1->next != first)
		temp1 = temp1->next;

	NODE temp2 = second;
	while (temp2->next != second)
		temp2 = temp2->next;

	temp1->next = second;
	temp2->next = first;

	return first;



}

int main() {
    NODE first = NULL, second = NULL;
    int x, pos, op, n;

    while (1) {
        printf("1.Create 2.Insert 3.Delete 4.Display 5.Reverse 6.Concat 7.Exit\n");
        printf("choice: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
                printf("How many nodes? ");
                scanf("%d", &n);
                first = createCLL(n);
                break;
            case 2:
                printf("Position: ");
                scanf("%d", &pos);
                if (pos <= 0) {
                    printf("Position not found\n");
                } else {
                    printf("Element: ");
                    scanf("%d", &x);
                    first = insertAtPositionInCLL(first, pos, x);
                }
                break;
            case 3:
                if (first == NULL) {
                    printf("CLL is empty\n");
                } else {
                    printf("Position: ");
                    scanf("%d", &pos);
                    first = deleteAtPositionInCLL(first, pos);
                }
                break;
            case 4:
                if (first == NULL) {
                    printf("CLL is empty\n");
                } else {
                    printf("Elements in CLL are: ");
                    traverseListInCLL(first);
                }
                break;
            case 5:
                if (first == NULL) {
                    printf("CLL is empty\n");
                } else {
                    first = reverseCLL(first);
                    printf("CLL reversed\n");
                    traverseListInCLL(first);   // <-- display reversed list
                }
                break;
            case 6:
                printf("Creating second CLL to concatenate...\n");
                printf("How many nodes in second CLL? ");
                scanf("%d", &n);
                second = createCLL(n);
                first = concatCLL(first, second);
                printf("Concatenated CLL:\n");
                traverseListInCLL(first);
                break;
            case 7:
                exit(0);
        }
    }
}
