#include <stdio.h>
#include <stdlib.h>

struct LinkedList {
    int data;
    struct LinkedList *next;
};

typedef struct LinkedList *Set;

Set createNode() {
    Set newNode = (Set)malloc(sizeof(struct LinkedList));
    newNode->data = 0;
    newNode->next = NULL;
    return newNode;
}

void display(Set head) {
    while(head != NULL) {
        printf("%d\t", head->data);
        printf("%d\n", head->next);
        head = head->next;
    }
    printf("\n");
}

Set merge(Set s1, Set s2) {
    Set s3 = NULL;
    Set curr = NULL;
    while(s1 != NULL || s2 != NULL) {
        if(s3 == NULL) {
            s3 = createNode();
            curr = s3;
        }
        else {
            curr->next = createNode();
            curr = curr->next;
        }

        if(s1 != NULL && s2 != NULL) {
            if(s1->data > s2->data) {
                curr->data = s1->data;
                s1 = s1->next;
            } 
            else if(s1->data < s2->data) {
                curr->data = s2->data;
                s2 = s2->next;
            }
            else {
                curr->data = s2->data;
                s1 = s1->next;
                s2 = s2->next;
            }
        }
        else if (s1 != NULL && s2 == NULL) {
            curr->data = s1->data;
            s1 = s1->next;
        }
        else if(s1 == NULL && s2 != NULL) {
            curr->data = s2->data;
            s2 = s2->next;
        }
    }
    return s3;
}

void main() {
    Set s1 = NULL, s2 = NULL, s3 = NULL, newElement = createNode();
    char c;

    printf("Enter elements of set 1\n");
    printf("Enter 1st  term\n");
    do {
        scanf("%d", &newElement->data);
        printf("1");
        s1 = merge(s1, newElement);
        printf("1");
        printf("Enter new term?[y/n]");
        scanf("%c", &c);
        scanf("%c", &c);
    }while(c == 'y' || c == 'Y');
    printf("\n\n");
    display(s1);
    printf("\n\n"); 
    printf("Enter elements of set 2");
    do {
        scanf("%d", &newElement->data);
        s2 = merge(s2, newElement);
        printf("Enter new term?[y/n]");
        scanf("%c", &c);
        scanf("%c", &c);
    }while(c == 'y' || c == 'Y');
    printf("\n\n");
    display(s2);
    printf("\n\n");

    s3 = merge(s1, s2);
    display(s3);
}