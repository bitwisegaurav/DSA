#include <stdio.h>
// Insertion Sort
int arr[20]={10,1,6,11,20,-4,5};
int size=7;

void display(){
    for (int i = 0; i < size; i++)
    {
        printf("%d,  ",arr[i]);
    }
    printf("\n\n");
}

void insertion(){
    int x,temp;
    for (int i = 1; i < size; i++)
    {
        x = arr[i];
        int j = 0;
        do{
            if (x<arr[j])
            {
                for (int k = i; k >= j; k--)
                {
                    arr[k] = arr[k-1];
                }
                arr[j] = x;
                break;
            }
            j++;
        }while(j<i);
    }
    printf("\n");
}

void insert(){
    int num;
    printf("Enter value ");
    scanf("%d",&num);
    size++;
    int j = 0;
    do{
        if (num<arr[j] || j==size-1)
        {
            for (int k = size; k >= j; k--)
            {
                arr[k] = arr[k-1];
            }
            arr[j] = num;
            break;
        }
        j++;
    }while(j<size);
    printf("\n");
}

void main(){
    int n;
    while (1)
    {
        printf("1 for sorting \n2 for inserting value \n3 to display \n4 to quit \nEnter number ");
        scanf("%d",&n);
        if (n==4)
        {    break;    }
        else if (n==1)
        {    insertion();    }
        else if (n==2)
        {    insert();    }
        else if (n==3)
        {    display();    }
    }
    printf("\n");
}