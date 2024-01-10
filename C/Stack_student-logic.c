#include <stdio.h>
#include <stdlib.h>
// Stack with dma(sourav's logic)
struct student{
    int roll;
    struct student *p;
};
struct student *ptr, *end, *temp;
void push(){
    if (ptr == NULL){
        ptr = (struct student *)malloc(sizeof(struct student));
        printf("Number bta bhai ");
        scanf("%d", &ptr->roll);
        ptr->p = NULL;
        end = ptr;
        printf("%d, %d, %d \n", ptr->roll, ptr->p, end->roll);
    }
    else{
        temp = (struct student *)malloc(sizeof(struct student));
        if (temp == NULL){
            printf("Memory bhar chuki hai\n");
        }
        else{
            printf("Number bta bhai ");
            scanf("%d", &temp->roll);
            temp->p = NULL;
            end->p = temp;
            end = temp;
            printf("%d, %d, %d \n", temp->roll, temp->p, end->roll);
        }
    }
}
void display(){
    temp = ptr;
    while (temp != NULL){
        printf("%d, ", temp->roll);
        temp = temp->p;
    }
    printf("\n");
}
void pop(){
    temp = ptr;
    while (temp->p != NULL){
        printf("%d, ", temp->roll);
        end = temp;
        temp = temp->p;
    }
    temp = end->p;
    free(temp);
    printf("\n");
}
void main(){
    int n;
    while (1){
        printf("1 daal push krne ke liye aur 2 daal pop krne ke liye aur 3 daal display krne ke liye aur 4 daal khatam krne ke liye ");
        scanf("%d", &n);
        if (n == 4){
            break;
        }
        else if (n == 1){
            push();
        }
        else if (n == 2){
            pop();
        }
        else if (n == 3){
            display();
        }
        else{
            printf("Sahi number daaliya\n");
        }
    }
    printf("\n");
}