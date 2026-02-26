#include <stdio.h>
#include <stdlib.h>

// Structure of a doubly linked list node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Head pointer of the first list
struct Node* head = NULL;

// Function to display the list
void display() {

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
   
   
   
}

// Function to insert a number at the end
void insert(int num) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = num;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    printf("Inserted successfully\n");
    
}

// Function to delete a specific number
void deleteNumber(int num) {
     if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;

    if (temp->data == num) {
        head = temp->next;
        free(temp);

        if (head == NULL) {
            printf("List is empty\n");
            return;
        }

        printf("List after deletion: ");
        struct Node* t = head;
        while (t != NULL) {
            printf("%d ", t->data);
            t = t->next;
        }
        printf("\n");
        return;
    }

    while (temp != NULL && temp->data != num) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Number %d not found\n", num);
        return;
    }

    prev->next = temp->next;
    free(temp);
if (head == NULL) {
    printf("List is empty\n");
    return;
}



    printf("List after deletion: ");
    struct Node* t = head;
    while (t != NULL) {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");

 
    
    
}

// Function to reverse the list
void reverseList() {
 if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;

    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

}

// Function to concatenate another list
void concatenate() {
  int n, num;

    scanf("%d", &n);
if (n == 0) {
        printf("Second list is empty\n");
        return;
}

    struct Node* head2 = NULL;
    struct Node* temp2 = NULL;

    for (int i = 0; i < n; i++) {
        scanf("%d", &num);

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = num;
        newNode->next = NULL;

        if (head2 == NULL) {
            head2 = newNode;
            temp2 = newNode;
        } else {
            temp2->next = newNode;
            temp2 = newNode;
        }
    }

    if (head == NULL) {
        head = head2;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = head2;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
}
printf("\n");

 
	
}

int main() {
    int choice, num;

    while (1) {
        printf("Enter operation\n1: Insert\n2: Delete\n3: Display\n4: Reverse\n5: Concatenate\n6: Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                scanf("%d", &num);
                insert(num);
                break;

            case 2:
                scanf("%d", &num);
                deleteNumber(num);
                break;

            case 3:
                display();
                break;

            case 4:
                reverseList();
                break;

            case 5:
                concatenate();
                break;

            case 6:
                printf("Exit\n");
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
