#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * llink;
    struct node * rlink;
};
typedef struct node * Node;
Node createnode(){
    Node nn=(Node)malloc(sizeof(struct node));
    printf("Enter the data for the new node\n");
    scanf("%d",&nn->data);
    nn->llink=nn->rlink=NULL;
    return nn;
}
void insertrear(Node Head){
    Node nn=createnode();
    nn->rlink=Head;
    nn->llink=Head->llink;
    Head->llink->rlink=nn;
    Head->llink=nn;
    Head->data++;
}
void display(Node Head){
    if(Head->data==0){
        printf("Nothing is present to display \n");
        return; 
    }else{
        Node start=Head->rlink;
        while(start!=Head){
            printf("%d\t",start->data);
            start=start->rlink;
        }
    }
}
void insertfront(Node Head){
    Node nn=createnode();
    nn->rlink=Head->rlink;
    nn->llink=Head->llink;
    Head->rlink->llink=nn;
    Head->rlink=nn;
    Head->data++;
}
void insertpos(Node Head){
    Node nn=createnode();
    printf("ENter the position \n");
    int pos;
    scanf("%d",&pos);
    int count=1;
    Node start=Head->rlink;
    while(count<pos-1){
        count++;
        start=start->rlink;
    }
    nn->rlink=start->rlink;
    nn->llink=start;
    start->rlink->llink=nn;
    start->rlink=nn;
    Head->data++;
}
void deletebypos(Node Head){
    int pos;
    printf("Enter the position\n");
    scanf("%d",&pos);
    int count=0;
    Node start=Head;
    while(count<pos){
        count++;
        start=start->rlink;
    }
    Node temp=start;
    temp->llink->rlink=temp->rlink;
    temp->rlink->llink=temp->llink;
    free(temp);
    Head->data--;
}
int main(){
    int lp=1;
    int choice;
    Node Head=(Node)malloc(sizeof(struct node));
    Head->data=0;
    Head->llink=Head->rlink=Head;
    while(lp){
        printf("Enter your choice \n");
        printf("1.insert front\n");
        printf("2.insert rear\n");
        printf("3.Display\n");
        printf("4.insert at a position\n");
        scanf("%d",&choice);
        switch(choice){
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
        }
    }
}



