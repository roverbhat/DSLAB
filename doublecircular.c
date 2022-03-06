#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *llink;
    struct node *rlink;
};
typedef struct node *Node;
Node createnode()
{
    Node nn = (Node)malloc(sizeof(struct node));
    printf("Enter the data for the new node\n");
    scanf("%d", &nn->data);
    nn->llink = nn->rlink = NULL;
    return nn;
}
void insertrear(Node Head)
{
    Node nn = createnode();
    nn->rlink = Head;
    nn->llink = Head->llink;
    Head->llink->rlink = nn;
    Head->llink = nn;
    Head->data++;
}
void display(Node Head)
{
    if (Head->data == 0)
    {
        printf("Nothing is present to display \n");
        return;
    }
    else
    {
        Node start = Head->rlink;
        while (start != Head)
        {
            printf("%d\t", start->data);
            start = start->rlink;
        }
    }
}
void insertfront(Node Head)
{
    Node nn = createnode();
    nn->rlink = Head->rlink;
    nn->llink = Head->llink;
    Head->rlink->llink = nn;
    Head->rlink = nn;
    Head->data++;
}
void insertpos(Node Head)
{
    Node nn = createnode();
    printf("ENter the position \n");
    int pos;
    scanf("%d", &pos);
    int count = 0;
    Node start = Head;
    while (count < pos - 1)
    {
        count++;
        start = start->rlink;
    }
    nn->rlink = start->rlink;
    nn->llink = start;
    start->rlink->llink = nn;
    start->rlink = nn;
    Head->data++;
}
void deletebypos(Node Head)
{
    int pos;
    printf("Enter the position\n");
    scanf("%d", &pos);
    int count = 0;
    Node start = Head;
    while (count < pos)
    {
        count++;
        start = start->rlink;
    }
    Node temp = start;
    temp->llink->rlink = temp->rlink;
    temp->rlink->llink = temp->llink;
    free(temp);
    Head->data--;
}
void deletebykey(Node Head)
{
    if (Head->data == 0)
    {
        printf("operation cannot be done at this stage\n");
        return;
    }
    Node start = Head->rlink;
    int key;
    printf("ENter the key elements\n");
    scanf("%d", &key);
    while (start != Head && start->data != key)
    {
        start = start->rlink;
    }
    if (start == Head)
    {
        printf("Key cannot be fouund\n");
    }
    start->llink->rlink = start->rlink;
    start->rlink->llink = start->llink;
    free(start);
    Head->data--;
}
void reverse(Node Head){
    if(Head->data==0 || Head->data==1){
        return;
    }
    Node start=Head->rlink;
    Node end=Head->llink;
    while(start!=end){
        int temp=start->data;
        start->data=end->data;
        end->data=temp;
        start=start->rlink;
        end=end->llink;
    }

}
int main()
{
    int lp = 1;
    int choice;
    Node Head = (Node)malloc(sizeof(struct node));
    Head->data = 0;
    Head->llink = Head->rlink = Head;
    while (lp)
    {
        printf("Enter your choice \n");
        printf("1.insert front\n");
        printf("2.insert rear\n");
        printf("3.Display\n");
        printf("4.insert at a position\n");
        printf("5.delete by pos\n");
        printf("6.Delete by key\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertfront(Head);
            break;
        case 2:
            insertrear(Head);
            break;
        case 3:
            display(Head);
            break;
        case 4:
            insertpos(Head);
            break;
        case 5:
            deletebypos(Head);
            break;
        case 6:
            deletebykey(Head);
            break;
        case 7:
            reverse(Head);
            printf("Linked list after reversing\n");
            display(Head);
        }
    }
}
