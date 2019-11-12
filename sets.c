#include <stdio.h>
#include <stdlib.h>

//Node structure for storing elements.
struct node
{
    int value;
    struct node *next;
};
//sample comment
typedef struct node element;

//Creates a node and returns it to the calling function.
element* createNode(int value)
{
    element* new = (element*)malloc(sizeof(element));       //Allocating memory to pointer of type element.
    new->value = value;
    new->next = NULL;
    return new;
}

//Inserts numbers into a set in ascending order.
element* insertElements(element* head, int value)
{    
    if(head == NULL)
       head = createNode(value);
    
    else
    {
        element *new, *temp1, *temp2;
        new = createNode(value);
        temp1 = head;
        
        while (temp1 != NULL)
        {
            if (new->value < temp1->value)
                break;
            
            else if (new->value == temp1->value)
            {
                printf("\nElement already exists in set.\n");
                goto l;    
            }
            
            temp2 = temp1;
            temp1 = temp1->next;
        }
        
        if (temp1 == head)
            head = new;
        
        else
            temp2->next = new;
        
        if (temp1 != NULL)
            new->next = temp1;
    }
    
    l: return head;
}

//Finds union of sets A & B.
element* setUnion(element* set1, element* set2)
{
    element *set3 = NULL, *temp, *new;
    
    while (set1 != NULL && set2 != NULL)
    {
        if (set1->value < set2->value)
        {
            new = createNode(set1->value);
            set1 = set1->next;
        }
        
        else if (set2->value < set1->value)
        {
            new = createNode(set2->value);
            set2 = set2->next;
        }
        
        else
        {
            new = createNode(set1->value);
            set1 = set1->next;
            set2 = set2->next;
        }
        
        if (set3 == NULL)
            temp = set3 = new;
        
        else
        {
            temp->next = new;
            temp = new;
        }
    }
    
    if (set1 == NULL)
    {
        while (set2 != NULL)
        {
            new = createNode(set2->value);
            temp->next = new;
            temp = new;
            set2 = set2->next;
        }
    }
    
    else
    {
        while(set1 != NULL)
        {
            new = createNode(set1->value);
            temp->next = new;
            temp = new;
            set1 = set1->next;
        }
    }
    
    return set3;
}

//Finds intersection of sets A & B.
element* setIntersection(element* set1, element* set2)
{
    element *set3 = NULL, *temp, *new;

    while(set1 != NULL && set2 != NULL)
    {
        new = NULL;
        
        if (set1->value < set2->value)          
            set1 = set1->next;
        
        else if (set2->value < set1->value)            
            set2 = set2->next;
        
        else if (set1->value == set2->value)
        {
            new = createNode(set1->value);
            set1 = set1->next;
            set2 = set2->next;
        }
        
        if (set3 == NULL)
            temp = set3 = new;
        
        else if (new != NULL)
        {
            temp->next = new;
            temp = new;
        }
    }

    return set3;
}

//Finds symmetric difference of sets A & B.
element* setSymDiff(element* set1, element* set2)
{
    element *set3 = NULL, *temp = NULL, *new;
    
    while(set1 != NULL && set2 != NULL)
    {
        new = NULL;
        if (set1->value < set2->value)
        {          
            new = createNode(set1->value);
            set1 = set1->next;
        }
        
        else if (set2->value < set1->value)
        {
            new = createNode(set2->value);
            set2 = set2->next;
        }

        else
        {
            set1 = set1->next;
            set2 = set2->next;
        }
        
        if (set3 == NULL)
            temp = set3 = new;
        
        else if (new != NULL)
        {
            temp->next = new;
            temp = new;
        }
    }
    
    if (set1 == NULL)
    {
        while (set2 != NULL)
        {
            new = createNode(set2->value);
            temp->next = new;
            temp = new;
            set2 = set2->next;
        }
    }
    
    else
    {
        while(set1 != NULL)
        {
            new = createNode(set1->value);
            temp->next = new;
            temp = new;
            set1 = set1->next;
        }
    }

    return set3;
}

//Displays a set.
void setDisplay(element* set)
{
    printf("{");
    while (set->next != NULL)
    {
        printf("%d, ", set->value);
        set = set->next;
    }

    printf("%d}", set->value);
}

void main()
{
    element* set1 = NULL;   //Set A.
    element* set2 = NULL;   //Set B.
    element* set3 = NULL;   //Set C, used according to requirement.
    
    int value;
    char choice;
    
    //Inserting elements in set A.
    printf("Enter elements of set A: ");
    do
    {
        printf("\nElement: ");
        scanf("%d", &value);
        set1 = insertElements(set1, value);
        printf("\nEnter another element? [Y/N]\n");
        scanf("%c", &choice);
        scanf("%c", &choice);
    } while (choice == 'y' || choice == 'Y');
    
    printf("\nSet A = ");
    setDisplay(set1);
    
    //Inserting elements in set A.
    printf("\n\nEnter elements of set B: ");
    do
    {
        printf("\nElement: ");
        scanf("%d", &value);
        set2 = insertElements(set2, value);
        printf("\nEnter another element? [Y/N]\n");
        scanf("%c", &choice);
        scanf("%c", &choice);
    } while (choice == 'y' || choice == 'Y');
    
    printf("\nSet B = ");
    setDisplay(set2);

    printf("\n");

    printf("\nA (union) B = ");
    set3 = setUnion(set1, set2);
    setDisplay(set3);
    printf("\n");
 
    printf("\nA (intersection) B = ");
    set3 = setIntersection(set1, set2);
    if (set3 == NULL)
        printf("phi");
                    
    else
       setDisplay(set3);
                    
    printf("\n");

    printf("\nA (symmetric diff) B = ");
    set3 = setSymDiff(set1, set2); 
    if(set3 == NULL)
        printf("phi");
                    
    else
        setDisplay(set3);
                    
    printf("\n\n");
}