#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * rlink;
    struct node * llink;
};
typedef struct node * Node;
Node  creatnode(){
    Node nn=(Node)malloc(sizeof(struct node));
    printf("Enter the data for the new node \n");
    scanf("%d",&nn->data);
    nn->rlink=nn->llink=NULL;
    return nn;
}
void insertrear(Node Head){
    Node nn=creatnode();
    if(Head->data==0){
        Head->llink=Head->rlink=nn;
        nn->rlink=NULL;
        nn->llink=Head;
    }
    else{
    Head->llink->rlink=nn;
    nn->llink=Head->llink;
    Head->llink=nn;
    nn->rlink=NULL;
    }
    Head->data++;
}
void insertfront(Node Head){
    Node nn=creatnode();
    if(Head->data==0){
        Head->llink=Head->rlink=nn;
    }
    else{
        nn->llink=Head;
        nn->rlink=Head->rlink;
        Head->rlink=nn;
    }
    Head->data++;
}
void display(Node Head){
    if(Head->data==0){
        printf("Nothing is present to display\n");
        return;
    }
    Node start=Head->rlink;
    while(start!=NULL){
        printf("%d\t",start->data);
        start=start->rlink;
    }
    printf("\n");
}
void deleterear(Node Head){
    if(Head->data==0){
        printf("Nothing is here to delete\n");
        return;
    }
    Node temp=Head->llink;
    Head->llink=temp->llink;
    temp->llink->rlink=NULL;
    free(temp);
    Head->data--;
}
void deletefront(Node Head){
    if(Head->data==0){
        printf("Cannot perfrom the dlete operation\n");
        return;
    }
    else{
        Node temp=Head->rlink;
        Head->rlink=temp->rlink;
        if(Head->data==1){
            Head->llink=NULL;
        }
        else{
        temp->rlink->llink=Head;
        }
        free(temp);
        Head->data--;
    }
}
void insertatpos(Node Head){
    Node nn=creatnode();
    int pos;
    printf("Enter the psoition\n");
    scanf("%d",&pos);
    Node start=Head;
    int count=0;
    while(start!=NULL && pos-1>count){
        count++;
        start=start->rlink;
    }
    if(pos==1 && Head->data==0){
            Head->llink=Head->rlink=nn;
    }
    else
    {
        nn->rlink=start->rlink;
        nn->llink=start;
        if(pos!=Head->data+1)
        start->rlink->llink=nn;
        start->rlink=nn;
    }
    Head->data++;
}
void deleteatpos(Node Head){
    if(Head->data==0){
        printf("empty list cannot be deleted\n");
        return;
    }
    Node start=Head;
    int count=0;
    int pos;
    printf("ENter the position \n");
    scanf("%d",&pos);
    while(start!=NULL && pos-1>count){
        start=start->rlink;
        count++;
    }
    printf("reached %d",start->data);
    Node temp=start->rlink;
    start->rlink=temp->rlink;
    if(pos==Head->data){
        start->llink=NULL;
    }
    else{
    temp->rlink->llink=start;
    }
     free(temp);
    Head->data--;
}
void reverse(Node Head){
    if(Head->data==0 || Head->data==1){
        return;
    }
    Node start=Head->rlink;
    Node end=Head->llink;
    int count=0;
    while(start!=end && count<(Head->data)/2){
        int temp;
        temp=start->data;
        start->data=end->data;
        end->data=temp;
        start=start->rlink;
        end=end->llink;
        count++;
    }
}
void deletebykey(Node Head){
    if(Head->data==0){
        printf("list is empty\n");
        return;
    }   
    int key;
    printf("Enter the key elements\n");
    scanf("%d",&key);
    Node start=Head->rlink;
    while(start!=NULL && start->data!=key)
    {
        start=start->rlink;
    }
    if(start==NULL){
        printf("Key not found\n");
        return;
    }
    Node temp=start->llink;
    temp->rlink=start->rlink;
    if(start->rlink!=NULL)
        start->rlink->llink=start->llink;
    free(start);
    Head->data--;
}

void main(){
    Node Head=(Node)malloc(sizeof(struct node));
    Head->data=0;
    Head->llink=Head->rlink=NULL;
    int cnt=1;
    int choice;
    while(cnt){
        printf("Enter your choice\n");
        printf("1.insert rear\n");
        printf("2.display\n");
        printf("3.Insert front\n");
        printf(" 4 Delete reaar\n");
        printf("5 delete front\n");
        printf("6 Insert by position\n");
        printf("7 delete at the position\n");
        printf("8 reverse a list\n");
        printf("9.delete by key \n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                insertrear(Head);
                break;
            case 2:
                display(Head);
                break;
            case 3:
                insertfront(Head);
                break;
            case 4:
                deleterear(Head);
                break;
            case 5:
                deletefront(Head);
                break;
            case 6:
                insertatpos(Head);
                break;
            case 7:
                deleteatpos(Head);
                break;
            case 8:
                reverse(Head);
                break;
            case 9:
                deletebykey(Head);
                break;
        }
    }
}