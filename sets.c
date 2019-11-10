#include<stdio.h>
#include<stdlib.h>
struct ele
{
    int val;
    struct ele*next;
};
struct ele*new;
struct ele*temp;
void createnode(int val)
{
    new=(struct ele*)malloc(sizeof(struct ele));
    new->next=NULL;
    new->val=val;
}
struct ele*insord(struct ele*head)
{
    struct ele*temp1;
    if(head==NULL)
       head=new;
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            if(new->val<=temp->val)
                break;
            temp1=temp;
            temp=temp->next;
        }
        if(temp==head)
            head=new;
        else
            temp1->next=new;
        if(temp!=NULL)
            new->next=temp;
    }
    return head;
}
struct ele*merge(struct ele*h,struct ele*h2)
{
    struct ele*h3=NULL;
    while(h!=NULL&&h2!=NULL)
    {
        if(h->val < h2->val)
        {
            createnode(h->val);
            h=h->next;
        }
        else if(h2->val < h->val)
        {
            createnode(h2->val);
            h2=h2->next;
        }
        else
        {
            createnode(h->val);
            h=h->next;
            h2=h2->next;
        }
        if(h3==NULL)
            temp=h3=new;
        else
        {
            temp->next=new;
            temp=new;
        }
    }
    if(h==NULL)
        while(h2!=NULL)
        {
            createnode(h2->val);
            temp->next=new;
            temp=new;
            h2=h2->next;
        }
    else
        while(h!=NULL)
        {
            createnode(h->val);
            temp->next=new;
            temp=new;
            h=h->next;
        }
    return h3;
}
struct ele* inter(struct ele* h,struct  ele* h2)
{
    struct ele* h3=NULL;
    temp = NULL;
    while(h!=NULL&&h2!=NULL)
    {
        new = NULL;
        if(h->val < h2->val)          
            h=h->next;
        else if(h2->val < h->val)            
            h2=h2->next;
        else
        {
            createnode(h->val);
            h=h->next;
            h2=h2->next;
        }
        if(h3==NULL)
            temp=h3=new;
        else
        {
            temp->next=new;
            temp=new;
        }
    }
    return h3;
}
void display(struct ele*h)
{
    printf("THE ELEMENTS ARE:  ");
    while(h->next!=NULL)
    {
        printf("%d , ",h->val);
        h=h->next;
    }
    printf("%d .",h->val);
}
void main()
{
    struct ele*head=NULL;
    struct ele*head2=NULL;
    int val;
    char ch;
    printf("enter elements of set 1\nenter first element\n");
    do
    {
        printf("element:");
        scanf("%d",&val);
        createnode(val);
        head=insord(head);
        printf("enter another element(y/n)");
        scanf("%c",&ch);
        scanf("%c",&ch);
    }while(ch=='y'||ch=='Y');
    printf("enter elements of set 2\nenter first element\n");
    do
    {
        printf("element:");
        scanf("%d",&val);
        createnode(val);
        head2=insord(head2);
        printf("enter another element(y/n)");
        scanf("%c",&ch);
        scanf("%c",&ch);
    }while(ch=='y'||ch=='Y');
    printf("THE TWO SETS ENTERED SUCCESSFULLY");
    do
    {
       printf("\n\nmenu for operations\n1. UNION\n2. INTERSECTION\n3. DHAIRYA\n4. EXIT");
       scanf("%d",&ch);
       switch (ch)
       {
        case 1:
           display(merge(head,head2));
           break;
        case 2:
                if(inter(head,head2)== NULL)
                    printf("no common elements...");
                else
                    display(inter(head,head2));
                break;    
        case 3:
            printf("dhairya karega case 3");
            break;
        case 4:
            printf("EXITING....");
            break;       
        default:
           printf("wrong choice....enter again");
       }
    }while (ch!=4);
}
