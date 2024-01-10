#include<stdio.h>
#include<stdlib.h>
// Single Linked List
int position=0,count=0;
struct student
{
    int roll;
    struct student *p;
};
struct student *ptr,*end,*temp,*pos;
void startpush(){
    if (ptr==NULL){
        ptr = (struct student*)malloc(sizeof(struct student));
        printf("Enter number to push ");
        scanf("%d",&ptr->roll);
        ptr->p = NULL;
        end = ptr;
        printf("%d is pushed\n",ptr->roll);
        count++;
    }
    else{
        temp = (struct student*)malloc(sizeof(struct student));
        if (temp==NULL)
        {
            printf("Memory is full\n");
        }
        else
        {
            printf("Enter number to push ");
            scanf("%d",&temp->roll);
            temp->p = ptr;
            ptr = temp;
            printf("%d is pushed\n",temp->roll);
            count++;
        }
    }
}
void endpush(){
    if (ptr==NULL)
    {
        ptr = (struct student*)malloc(sizeof(struct student));
        printf("Enter number to push ");
        scanf("%d",&ptr->roll);
        ptr->p = NULL;
        end = ptr;
        printf("%d is pushed\n",ptr->roll);
        count++;
    }
    else{
        temp = (struct student*)malloc(sizeof(struct student));
        if (temp==NULL)
        {
            printf("Memory is full\n");
        }
        else
        {
            printf("Enter number to push ");
            scanf("%d",&temp->roll);
            temp->p = NULL;
            end->p = temp;
            end = temp;
            printf("%d is pushed\n",temp->roll);
            count++;
        }
    }
}
void pos_push(){
    printf("Enter position at which you want enter ");
    scanf("%d",&position);
    if (position>=1 && position<=count+1)
    {
        if (position==1){
            startpush();
        }
        else{
            temp = (struct student*)malloc(sizeof(struct student));
            if (temp==NULL){    printf("Memory is full\n");    }
            else{
                printf("Enter number to push ");
                scanf("%d",&temp->roll);
                pos = ptr;
                for (int i = 1; i < position-1; i++)
                {
                    pos = pos->p;
                }
                temp->p = pos->p;
                pos->p = temp;
                printf("%d is pushed at %d position\n",temp->roll,position);
                count++;
            }
        }
    }
    else{   printf("Enter valid position\n");  }
}
void pos_pop(){
    printf("Enter position at which you want enter ");
    scanf("%d",&position);
    if (position>=1 && position<=count)
    {
        pos = ptr;
        for (int i = 1; i < position-1; i++)
        {
            pos = pos->p;
        }
        temp = pos->p;
        pos->p = temp->p;
        printf("%d is deleted\n",temp->roll);
        free(temp);
        count--;
    }
    else{   printf("Enter valid position\n");  }
}
void startpop(){
    if(ptr==NULL){    printf("List is empty\n");    }
    else{
        temp = ptr;
        ptr = temp->p;
        printf("%d is deleted\n",temp->roll);
        free(temp);
        count--;
    }
}
void endpop(){
    if(ptr==NULL){    printf("List is empty\n");    }
    else{
        temp = ptr;
        if (temp->p!=NULL)
        {
            while (temp->p!=NULL)
            {
                end = temp;
                temp = temp->p;
            }
            temp = end->p;
            end->p = NULL;
        }
        printf("%d is deleted\n",temp->roll);
        free(temp);
        count--;
    }
}
void display(){
    if(ptr==NULL){    printf("List is empty\n");    }
    else{
        temp = ptr;
        while (temp!=NULL)
        {
            printf("%d, ",temp->roll);
            temp = temp->p;
        }
        printf("\n--------------------------\n");
    }
}
void main(){
    int n;
    while (1)
    {
        printf("\n1 for push from start \n2 for push from end \n3 for push at specific position  \n4 for pop from start  \n5 for pop from end \n6 for pop at specific position \n7 for display \n8 to exit \nEnter number from above ");
        scanf("%d",&n);
        if (n==8){    break;    }
        else if (n==1){    startpush();    }
        else if (n==2){    endpush();    }
        else if (n==3){    pos_push();    }
        else if (n==4){    startpop();    }
        else if (n==5){    endpop();    }
        else if (n==6){    pos_pop();    }
        else if (n==7){    display();    }
        else{   printf("Enter valid number\n");    }
    }
    printf("\n");
}