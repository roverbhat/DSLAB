//dynamic allocation of fixed sized array and all value are passed by reference 
//dont confuse with vector in STL..............
#include <stdio.h>
#include <stdlib.h>
int n;
void getdata(int *arr)
{
    printf("Eneter the data \n");
    n++;
    scanf("%d", (arr + n));
}
void display(int *arr)
{
    for (int i = 0; i <= n; i++)
    {
        printf("%d\t", *(arr + i));
    }
    printf("\n");
}
void insertatpos(int *arr){
    int pos;
    printf("Enter the position\n");
    scanf("%d",&pos);
    pos=pos-1;
    for(int i=n;i>=pos;i--){
        *(arr+i+1)=*(arr+i);
    }
    scanf("%d",(arr+pos));
    n++;
}
void deletebypos(int *arr){
    int pos;
    printf("Enter the position\n");
    scanf("%d",&pos);
    pos=pos-1;
    for(int i=pos;i<n;i++){
        *(arr+i)=*(arr+i+1);
    }
    n--;
}
void sort(int * arr){
    int temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            if(*(arr+j)>*(arr+j+1)){
                temp=*(arr+j);
                *(arr+j)=*(arr+j+1);
                *(arr+j+1)=temp;
            }
        }
    }
}
void search(int * arr){
    int key;
    printf("Enter the key element to be searched\n");
    scanf("%d",&key);
    for(int i=0;i<=n;i++){
        if(*(arr+i)==key){
            printf("Key %d is found at location %d\n",key,(i+1));
            return;
        }
    }
    printf("key is not found at this present check the array and try again\n");
}
void deletebykey(int * arr){
    int key;
    printf("Enter the key element\n");
    scanf("%d",&key);
    int res=-1;
    for(int i=0;i<=n;i++){
        if(*(arr+i)==key){
            res=i;
            break;
        }
    }
    if(res!=-1){
        for(int i=res;i<n;i++){
            *(arr+i)=*(arr+i+1);
        }
        n--;
    }
    else{
        printf("Key is not present to delete please try again later \n");
    }
}
void insertbyordera(int *arr){
    //for insert by order the aray must be sorted;
    sort(arr);
    printf("Enter the element\n");
    int data;
    int pos;
    scanf("%d",&data);
    for(int i=n;i>=0;i--){
        if(data>=*(arr+i)){
            pos=i+1;
            break;
        }
    }
    for(int i=n;i>=pos;i--){
        *(arr+i+1)=*(arr+i);
    }
    *(arr+pos)=data;
    n++;
}
int main()
{
    int lp = 1;
    int choice;
    n = -1;
    //dynamic alllocation using malloc function
    int *arr=(int *)malloc(100*sizeof(int));
    //satic allocation;
   // int arr[100];
    while (lp)
    {
        printf("Enter your choice \n");
        printf("1 Enter the element at end \n");
        printf("2.display the elements\n");
        printf("3 Insert at position \n");
        printf("2>delete at a psoition \n");
        printf("5.sort\n");
        printf("6.search\n");
        printf("7.delete by key\n");
        printf("8.Insert by order\n");
        printf("9.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            getdata(arr);
            break;
        case 2:
            display(arr);
            break;
        case 3:
            insertatpos(arr);
            break;
        case 4:
            deletebypos(arr);
            break;
        case 5:
            sort(arr);
            break;
        case 6:
            search(arr);
            break;
        case 7:
            deletebykey(arr);
            break;
        case 8:
            insertbyordera(arr);
            break;
        case 9:
            free(arr);
            lp=0;
            break;
        default:
            printf("Invalid Entry \n");
        }
    }
}