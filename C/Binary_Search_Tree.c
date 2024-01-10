#include <stdio.h>
#include <stdlib.h>
// Binary Tree
struct tree
{
    int data;
    struct tree *right, *left;
}*ptr,*end,*temp;

void insert(){
    temp = (struct tree*)malloc(sizeof(struct tree));
    printf("Enter data ");
    scanf("%d",&temp->data);
    temp->right = NULL;
    temp->left = NULL;
    if (ptr==NULL){
        ptr = temp;
        printf("%d\n\n",ptr->data);
    }
    else{
        end = ptr;
        printf("%d, ",end->data);
        while (1){
            if ((end->data)==(temp->data)){
                break;
            }
            else if ((end->data)>(temp->data)){
                if (end->left==NULL)
                    break;
                else
                    end = end->left;
            }
            else{
                if (end->right==NULL)
                    break;
                else
                    end = end->right;
            }
            printf("%d, ",end->data);
        }
        if ((end->data)==(temp->data)){
            printf("\nThis number is already inserted\n");
        }
        else{
            if ((end->data)>(temp->data)){
                end->left = temp;
            }
            else{
                end->right = temp;
            }
            printf("%d\n\n",temp->data);
        }
    }
}

void preorder(struct tree *t){
    if(t!=NULL){
        printf("%d, ",t->data);
        preorder(t->left);
        preorder(t->right);
    }
}

void inorder(struct tree *t){
    if(t!=NULL){
        inorder(t->left);
        printf("%d, ",t->data);
        inorder(t->right);
    }
}

void postorder(struct tree *t){
    if(t!=NULL){
        postorder(t->left);
        postorder(t->right);
        printf("%d, ",t->data);
    }
}

void delete(){
    int num;
    struct tree *t;
    printf("Enter number you want to delete ");
    scanf("%d",&num);
    if (ptr==NULL){
        printf("Tree is empty\n\n");
    }
    else{
        end = ptr;
        temp = end;
        while (1){
            if ((end->data)==num){
                break;
            }
            else if ((end->data)>num){
                if (end->left==NULL){
                    break;
                }
                else
                    temp = end;
                    end = end->left;
            }
            else{
                if (end->right==NULL)
                    break;
                else{
                    temp = end;
                    end = end->right;
                }
            }
        }
        if ((end->data)==num){
            printf("Data exists\n");
            if (end->right==NULL && end->left==NULL){
                printf("No child \n%d is deleted\n\n",end->data);
                if (temp->left==end){
                    temp->left = NULL;
                    free(end);
                }
                else{
                    temp->right = NULL;
                    free(end);
                }
            }
            else if (end->right==NULL || end->left==NULL){
                printf("One child \n%d is deleted\n\n",end->data);
                if (temp->left==end){
                    if (end->right==NULL)
                        temp->left = end->left;
                    else
                        temp->left = end->right;
                    free(end);
                }
                else{
                    if (end->right==NULL)
                        temp->right = end->left;
                    else
                        temp->right = end->right;
                    free(end);
                }
            }
            else{
                printf("Two child \n%d is deleted\n\n",end->data);
                temp = end->right;
                while (1)
                {
                    t = temp;
                    temp = temp->left;
                    if (temp->left==NULL)
                        break;
                }
                // printf("---%d\n",t->data);
                if (temp->right!=NULL)
                    t->left = temp->right;
                else
                    t->left = NULL;
                end->data = temp->data;
                free(temp);
            }
        }
        else{
            printf("Data does not exist\n\n");
        }
    }
}

void main(){
    int n;
    while (n!=6){
        printf("1 for insert \n2 for preorder search \n3 for inorder search \n4 for postorder search \n5 for delete \n6 for quit \nEnter value ");
        scanf("%d",&n);
        if (n==1){ insert(); }
        else if (n==2){ preorder(ptr); printf("\n\n"); }
        else if (n==3){ inorder(ptr); printf("\n\n"); }
        else if (n==4){ postorder(ptr); printf("\n\n"); }
        else if (n==5){ delete(); }   
    }
}