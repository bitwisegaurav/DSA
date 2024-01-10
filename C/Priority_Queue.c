#include<stdio.h>
#include<stdlib.h>
// Priority Queue 
struct queue
{
    int data;
    int priority;
    struct queue *p;
}*ptr,*end,*temp,*pre;

void display(){
    if(ptr==NULL){ printf("Queue is empty\n"); }
    else{
        end = ptr;
        while (end!=NULL){
            printf("%d,%d\n",end->data,end->priority);
            end = end->p;
        }
        printf("--------------------------\n");
    }
}

void insert(){
    temp = (struct queue*)malloc(sizeof(struct queue));
    printf("Enter data ");
    scanf("%d",temp->data);
    printf("Enter priority ");
    scanf("%d",temp->priority);
    temp->p = NULL;
    
    if (ptr==NULL){    ptr = temp;    }
    else{
        if (temp==NULL){    printf("Memory is full\n");    }
        else{
            pre = ptr;
            //display();
            //printf("\n%d, %d\n",ptr->priority,temp->priority);
            if (ptr->priority<=temp->priority){
                end = ptr;
                //printf("\n--------\n");
                while (end!=NULL){
                    if ((end->priority>temp->priority)){
                        break;
                    }
                    pre = end;
                    end = end->p;
                }
                temp->p = pre->p;
                pre->p = temp;
            }
            else{
                temp->p = ptr;
                ptr = temp;
            }
        }
    }
}

void delete(){
    if(ptr==NULL){ printf("Queue is empty\n"); }
    else{
        temp = ptr;
        ptr = temp->p;
        printf("%d of priority %d is deleted\n",temp->data,temp->priority);
        free(temp);
    }
}

void main(){
    int n;
    while (n!=4)
    {
        printf("\n1 to inert \n2 to delete \n3 to display \n4 to exit \nEnter number from above ");
        scanf("%d",n);

        if (n==4){ break; }
        else if (n==1){ insert(); }
        else if (n==2){ delete(); }
        else if (n==3){ display(); }
        else{ printf("Enter valid number\n"); }
    }
    printf("\n");
}