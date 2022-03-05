#include <stdio.h>
#include <stdlib.h>
struct student
{
    int mark[3];
    int regno;
    char name[10];
    float avg;
};
typedef struct student student;
void getdata(student *s, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Enter the reg of %d student\n ", i + 1);
        scanf("%d", &(s + i)->regno);
        printf("Enter the name \n");
        scanf("%s", &(s + i)->name);
        printf("Enter the first subjet marks\n");
        scanf("%d", &(s + i)->mark[0]);
        printf("Enter the second subjet marks\n");
        scanf("%d", &(s + i)->mark[1]);
        printf("Enter the third subjet marks\n");
        scanf("%d", &(s + i)->mark[2]);
    }
}
void display(student *s, int n)
{
    printf("Name\tregno\tsub1\tsub2\tsub3\tavg\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s\t%d\t%d\t%d\t%d\t%f\n", (s + i)->name, (s + i)->regno, (s + i)->mark[0], (s + i)->mark[1], (s + i)->mark[2], (s + i)->avg);
    }
}
void calavg(student *s, int n)
{
    for (int i = 0; i < n; i++)
    {
        int min = (s + i)->mark[0];
        for (int j = 0; j < 3; j++)
        {
            if ((s + i)->mark[j] < min)
            {
                min = (s + i)->mark[j];
            }
        }
        int total = (s + i)->mark[0] + (s + i)->mark[1] + (s + i)->mark[2];
        (s + i)->avg = (total - min) / 2.0;
    }
}
int main()
{
    int choice;
    int cnt = 1;
    int n;
    printf("enter the number of students\n");
    scanf("%d", &n);
    student *s = (student *)malloc(n * sizeof(struct student));
    while (cnt)
    {
        printf("1.Enter the student details\n");
        printf("2.display the student details\n");
        printf("3.cal avag\n");
        printf("4.Exit the program\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            getdata(s, n);
            break;
        case 2:
            display(s, n);
            break;
        case 3:
            calavg(s, n);
            break;
        case 4:
            cnt = 0;
            break;
        }
    }
}