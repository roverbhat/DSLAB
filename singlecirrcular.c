#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * link;
};
typedef struct node * Node;
Node createnode(){
    Node nn=(Node)malloc(sizeof(struct node));
    printf("Enter the data for the new node\n");
    scanf("%d",&nn->data);
    nn->link=NULL;
    return nn;
}
void insertrear(Node Head){
    Node nn=createnode();
    if(Head->link==Head){
        Head->link=nn->link=nn;
    }
    else{
        nn->link=Head->link->link;
        Head->link->link=nn;
        Head->link=nn;
    }
    Head->data++;
}
void display(Node Head){
    if(Head->data==0){
        printf("Nothing is here to display \n");
        return;
    }
    Node first=Head->link->link;
    do{
        printf("%d\t",first->data);
        first=first->link;
    }while(first!=Head->link->link);
    printf("\n");
}
void insertfront(Node Head){
    Node nn=createnode();
    if(Head->data==0){
        nn->link=nn;
        Head->link=nn;
    }
    else{
        nn->link=Head->link->link;
        Head->link->link=nn;
    }
    Head->data++;
}
void insertpos(Node head){
    int pos;
    printf("ENter the pos\n");
    scanf("%d",&pos);
    if(pos>head->data+1|| pos<0){
        printf("Invalid pos\n");
        return;
    }
    int count=1;
    Node nn=createnode();
    Node start=head->link->link;
    while(count<pos-1){
        start=start->link;
        count++;
    }
    if(pos==1){
        if(head->data==0){
            nn->link=nn;
            head->link=nn;
            head->data++;
            return;
        }
        nn->link=start;
        head->link->link=nn;
    }
    else{
    nn->link=start->link;
    start->link=nn;
    if(pos==head->data+1){
        head->link=nn;
    }
    }
    head->data++;
    
}
int main(){
    Node Head=(Node)malloc(sizeof(struct node));
    Head->data=0;
    Head->link=Head;
    int cnt=1;
    int choice;
    while(cnt){
        printf("Enter your choice\n");
        printf("1.Insert rear\n");
        printf("2.display\n");
        printf("3.Insert front\n");
        printf("Insert at pos\n");
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
                insertpos(Head);
                break;
        }
    }
}