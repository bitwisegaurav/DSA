#include <stdio.h>
// Queue
int i=-1,j=-1,num=0;

int insert(int a[],int size){
    if(i==size-1){
        printf("Queue is full\n\n");
        return 0;
    }
    else{
        i++;
        printf("Enter number ");
        scanf("%d",&num);
        printf("\n");
        return 1;
    }
}

void delete(int a[]){
    if(i==-1 || i<=j){
        printf("Queue is empty\n\n");
    }
    else{
        j++;
        printf("%d is deleted\n\n",a[j]);
    }
}

void reset(){
    i=-1,j=-1;
}

void main()
{
    int arr[5]={0},x,n;
    
    while(1){
        printf("1 for insert \n2 for delete \n3 for reset \n4 for quit");
        printf("\nEnter number from above ");
        scanf("%d",&x);
        switch(x){
            case 1:
                printf("inserting\n");
                n = insert(arr,5);
                if(n==1)
                    arr[i] = num;
                break;
            case 2:
                printf("deleting\n");
                delete(arr);
                break;
            case 3:
                printf("reseting\n");
                
                reset();
                break;
            case 4:
                printf("quiting\n");
                break;
            default:
                printf("Enter valid number");
                break;
        }
        if(x==4)
            break;
    }
}