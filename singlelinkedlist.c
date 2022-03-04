#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
typedef struct node *Node;
Node createnode()
{
    Node newnode = (Node)malloc(sizeof(struct node));
    printf("Enter the data \n");
    scanf("%d", &newnode->data);
    newnode->link = NULL;
    return newnode;
}
void insertrear(Node Head)
{
    Node newnode = createnode();
    if (Head->data == 0)
    {
        Head->link = newnode;
    }
    else
    {
        Node temp = Head->link;
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = newnode;
    }
    Head->data++;
}
void display(Node Head)
{
    if (Head->data == 0)
    {
        printf("EMPTY LIST CANNOT BE DISPLAYED \n");
    }
    else
    {
        Node temp = Head->link;
        while (temp != NULL)
        {
            printf("%d \t", temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
}
void deleterear(Node Head)
{
    if (Head->data == 0)
    {
        printf("notheing is here to delete \n");
    }
    else
    {
        Node next = Head->link;
        Node prev = Head;
        while (next->link != NULL)
        {
            prev = prev->link;
            next = next->link;
        }
        printf("Deleting %d \n ", next->data);
        prev->link = next->link;
        free(next);
        Head->data--;
    }
}
void insertfront(Node Head)
{
    Node newnode = createnode();
    newnode->link = Head->link;
    Head->link = newnode;
    Head->data++;
}
void sort(Node Head)
{
    if (Head->data == 0 || Head->data == 1)
        return;
    int tempv;
    int count = 1;
    while (count < Head->data)
    {
        // Node prev=Head;
        Node temp = Head->link;
        while (temp->link != NULL)
        {
            if (temp->data > temp->link->data)
            {
                tempv = temp->data;
                temp->data = temp->link->data;
                temp->link->data = tempv;
            }
            temp = temp->link;
        }
        count++;
    }
}
int search(Node Head, int key)
{
    if (Head->data == 0)
    {
        printf("cannot search for an element  in a empty list\n");
    }
    else
    {
        Node temp = Head->link;
        int count = 1;
        while (temp != NULL && temp->data != key)
        {
            temp = temp->link;
            count++;
        }
        if (temp == NULL)
            return -1;
        return count;
    }
}
void insertbyposition(Node Head)
{
    int pos;
    int count = 1;
    printf("enter the position\n");
    scanf("%d", &pos);
    Node temp = Head->link;
    while (count < pos - 1)
    {
        temp = temp->link;
        count++;
    }
    Node newnode = createnode();
    if (pos == 1)
    {
        newnode->link = Head->link;
        Head->link = newnode;
    }
    else
    {
        newnode->link = temp->link;
        temp->link = newnode;
    }
    Head->data++;
}
void deletefront(Node Head)
{
    if (Head->data == 0)
    {
        printf("Node cannot de deleted \n");
    }
    else
    {
        Node dn = Head->link;
        printf("Deleting %d ......\n", dn->data);
        Head->link = dn->link;
        Head->data--;
    }
}
void deletebypos(Node Head)
{
    int pos;
    printf("Enter the postion of the node to be deleted \n");
    scanf("%d", &pos);
    int count = 0;
    Node temp = Head;
    while (count < pos - 1)
    {
        temp = temp->link;
        count++;
    }
    printf("You reached %d ", temp->data);
    printf(" deleting %d", temp->link->data);
    Node dn = temp->link;
    temp->link = temp->link->link;
    free(dn);
}
void deletekey(Node Head)
{
    if (Head->data == 0)
    {
        printf("empty list cannot be deleted\n");
        return;
    }
    int key;
    printf("Enter the key element\n");
    scanf("%d", &key);
    Node temp = Head->link;
    Node prev = Head;
    while (temp != NULL && key != temp->data)
    {
        prev = temp;
        temp = temp->link;
    }
    prev->link = temp->link;
    printf("deleting %d ", temp->data);
    free(temp);
}
int main()
{
    int loop = 1;
    int choice;
    Node Head = (Node)malloc(sizeof(struct node));
    Head->data = 0;
    Head->link = NULL;
    while (loop)
    {
        printf("Enter your choice \n");
        printf(" 1 ----insert at rear\n");
        printf("2.Delete at the rear\n");
        printf("3 --- Display  \n");
        printf("4.insert at the front\n");
        printf("5.delte at the front \n");
        printf("6.sort\n");
        printf("7.Insert by position \n");
        printf("8.delete by pos\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertrear(Head);
            break;
        case 2:
            deleterear(Head);
            break;
        case 3:
            display(Head);
            break;
        case 4:
            insertfront(Head);
            break;
        case 5:
            deletefront(Head);
            break;
        case 6:
            sort(Head);
            break;
        case 7:
            insertbyposition(Head);
            break;
        case 8:
            deletebypos(Head);
            break;
        case 9:
            deletekey(Head);
            break;
        }
    }
}