#include<stdio.h>
#include<stdlib.h>
// Doubly Circluar Linked List
int position=0,count=0;
struct student
{
    int roll;
    struct student *pre;
    struct student *post;
};
struct student *ptr,*end,*temp,*pos;
void startpush(){
    if (ptr==NULL){
        ptr = (struct student*)malloc(sizeof(struct student));
        printf("Enter number to push ");
        scanf("%d",&ptr->roll);
        ptr->pre = NULL;
        ptr->post = NULL;
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
            temp->pre = end;
            temp->post = ptr;
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
        ptr->pre = NULL;
        ptr->post = NULL;
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
            temp->pre = end;
            temp->post = ptr;
            end->post = temp;
            end = temp;
            ptr->pre = temp;
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
        if (ptr==NULL){
            ptr = (struct student*)malloc(sizeof(struct student));
            printf("Enter number to push ");
            scanf("%d",&ptr->roll);
            ptr->post = NULL;
            end = ptr;
            printf("%d is pushed at %d position\n",ptr->roll,position);
            count++;
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
                    pos = pos->post;
                }
                temp->post = pos->post;
                pos->post = temp;
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
            pos = pos->post;
        }
        temp = pos->post;
        pos->post = temp->post;
        printf("%d is deleted\n",temp->roll);
        free(temp);
        count--;
    }
    else{   printf("Enter valid position\n");  }
}
void startpop(){
    if(ptr==NULL){    printf("Stack is empty\n");    }
    else{
        temp = ptr;
        ptr = temp->post;
        ptr->pre = end;
        printf("%d is deleted\n",temp->roll);
        free(temp);
        count--;
    }
}
void endpop(){
    if(ptr==NULL){    printf("Stack is empty\n");    }
    else{
        temp = ptr;
        if (temp->post!=NULL)
        {
            for (int i = 1; i < count; i++)
            {
                end = temp;
                temp = temp->post;
            }
            temp = end->post;
            end->post = ptr;
            ptr->pre = end;
        }
        printf("%d is deleted\n",temp->roll);
        free(temp);
        count--;
    }
}
void display(){
    if(ptr==NULL){    printf("Stack is empty\n");    }
    else{
        temp = ptr;
        for (int i = 1; i <= count; i++)
        {
            printf("%d, ",temp->roll);
            temp = temp->post;
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