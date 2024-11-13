#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
};


struct node *new, *head = NULL, *ptr, *temp, *prevNode, *curr;


void insert_front(int item) {
    new = (struct node*)malloc(sizeof(struct node));
    new->data = item;
    new->next = head;  
    new->prev = NULL;  
    
    if (head != NULL) {
        head->prev = new;  
    }
    
    head = new;  
    printf("Inserted %d at the front.\n", item);
}


void insert_end(int item) {
    new = (struct node*)malloc(sizeof(struct node));
    new->data = item;
    new->next = NULL;  
    new->prev = NULL;  
    
    if (head == NULL) {
        head = new;  
    } else {
        ptr = head;
        while (ptr->next != NULL) {  
            ptr = ptr->next;
        }
        ptr->next = new;  
        new->prev = ptr;  
    }
    printf("Inserted %d at the end.\n", item);
}


void insert_specific(int key, int item) {
    ptr = head;
    while (ptr != NULL && ptr->data != key) { 
        ptr = ptr->next;
    }
    
    if (ptr == NULL) {
        printf("Item with value %d not found.\n", key);
    } else {
        new = (struct node*)malloc(sizeof(struct node));
        new->data = item;
        new->next = ptr->next;  
        new->prev = ptr;       
        
        if (ptr->next != NULL) {
            ptr->next->prev = new; 
        }
        ptr->next = new;  
        printf("Inserted %d after %d.\n", item, key);
    }
}


void delete_front() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    
    temp = head;  
    head = head->next;  
    
    if (head != NULL) {
        head->prev = NULL;  
    }
    
    free(temp); 
    printf("Deleted item from the front.\n");
}


void delete_end() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    
    if (head->next == NULL) {  
        free(head);
        head = NULL;
    } else {
        ptr = head;
        while (ptr->next != NULL) {  
            ptr = ptr->next;
        }
        ptr->prev->next = NULL; 
        free(ptr);  
    }
    printf("Deleted item from the end.\n");
}


void delete_specific(int key) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    
    ptr = head;
    if (ptr->data == key) {  
        head = ptr->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(ptr);
        printf("Deleted item %d.\n", key);
        return;
    }
    
    while (ptr != NULL && ptr->data != key) {  
        ptr = ptr->next;
    }
    
    if (ptr == NULL) {
        printf("Item with value %d not found.\n", key);
    } else {
        ptr->prev->next = ptr->next;  
        if (ptr->next != NULL) {
            ptr->next->prev = ptr->prev;  
        }
        free(ptr);
        printf("Deleted item %d.\n", key);
    }
}


void display() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    
    ptr = head;
    printf("The list is: ");
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}


void display_reverse() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    
    ptr = head;
    while (ptr->next != NULL) {  
        ptr = ptr->next;
    }
    
    printf("The list in reverse is: ");
    while (ptr != NULL) {  
        printf("%d ", ptr->data);
        ptr = ptr->prev;
    }
    printf("\n");
}


int main() {
    int opt, key, item;
    
    do {
        printf("\nChoose an operation:\n");
        printf("1. Insert at front\n");
        printf("2. Insert at end\n");
        printf("3. Insert after a specific node\n");
        printf("4. Delete from front\n");
        printf("5. Delete from end\n");
        printf("6. Delete a specific item\n");
        printf("7. Display the list\n");
        printf("8. Display the list in reverse\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &opt);
        
        switch(opt) {
            case 1:
                printf("\nEnter the element to be inserted at front: ");
                scanf("%d", &item);
                insert_front(item);
                break;
            case 2:
                printf("\nEnter the element to be inserted at end: ");
                scanf("%d", &item);
                insert_end(item);
                break;
            case 3:
                printf("\nEnter the element after which item should be inserted: ");
                scanf("%d", &key);
                printf("\nEnter the element to be inserted after %d: ", key);
                scanf("%d", &item);
                insert_specific(key, item);
                break;
            case 4:
                delete_front();
                break;
            case 5:
                delete_end();
                break;
            case 6:
                printf("\nEnter the item to be deleted: ");
                scanf("%d", &key);
                delete_specific(key);
                break;
            case 7:
                display();
                break;
            case 8:
                display_reverse();
                break;
            case 9:
                printf("Exiting program.\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while(opt != 9);
    
    return 0;
}
