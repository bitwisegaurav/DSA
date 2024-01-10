#include <stdio.h>
#include <string.h>
// Infix to Postfix and Prefix

int num;
// char infix[70]="(((z*b/)-(b-a))/(a-b*c^d))";
// char infix[70]="((((a+b*d)*(b^c/d))^((a+b)-(b-a)))/(a-b*c^d))";
// char infix[70]="(((a-b)))))))";
char infix[20];
char stack[40],post[70];
int n=-1,k=0;

int prescedence(int x){
    if(infix[x]=='^' || (infix[x]=='(' && num==1) || (infix[x]==')' && num==2)){
        n++;
        stack[n]=infix[x];
        return 1;
    }
    else if(infix[x]=='*' || infix[x]=='/'){
        if(stack[n]=='^' || stack[n]=='*' || stack[n]=='/'){
            post[k]=stack[n];
            k++;
            n--;
            return 0;
        }
        else{
            n++;
            stack[n]=infix[x];
            return 1;
        }
    }
    else if(infix[x]=='+' || infix[x]=='-'){
        if(stack[n]=='^' || stack[n]=='*' || stack[n]=='/'  || stack[n]=='+' || stack[n]=='-'){
            post[k]=stack[n];
            k++;
            n--;
            return 0;
        }
        else{
            n++;
            stack[n]=infix[x];
            return 1;
        }
    }
    else if((infix[x]==')' && num==1)||(infix[x]=='(' && num==2)){
        if(num==1){
            while(stack[n]!='(') {
                if(stack[n]=='\0')
                    break;
                post[k]=stack[n];
                k++;
                n--;
            }
            post[k]=stack[n];
            k++;
            n--;
        }
        else if(num==2){
            while(stack[n]!=')') {
                if(stack[n]=='\0')
                    break;
                post[k]=stack[n];
                k++;
                n--;
            }
            post[k]=stack[n];
            k++;
            n--;
        }
        return 1;
    }
}

void postfix(){
    int check;
    for (int i = 0; infix[i]!='\0'; i++) {
        if((infix[i]>='0' && infix[i]<='9')||(infix[i]>='a' && infix[i]<='z')||(infix[i]>='A' && infix[i]<='Z'))
        {
            post[k]=infix[i];
            k++;
        }
        else{
            if(n!=-1){
                do{
                    check = prescedence(i);
                }while(check!=1);
            }
            else{
                n++;
                stack[n]=infix[i];
            }
        }
    }
    for (int i = n; i >= 0; i--) {
        post[k]=stack[i];
        k++;
    }
}

void prefix(){
    int n=0;
    char a[10];
    // for (int i = 0; infix[i]!='\0'; i++) {
    //     a[i]=infix[i];
    //     n++;
    // }
    // for (int i = 0; n>0; i++) {

    //     infix[i]=a[n-1];
    //     n--;
    // }
    strrev(infix);
    postfix();

    // for (int i = 0; post[i]!='\0'; i++) {
    //     a[i]=post[i];
    //     n++;
    // }
    // for (int i = 0; n>0; i++) {
    //     post[i]=a[n-1];
    //     n--;
    // }
    strrev(post);
}

void main()
{
    printf("Enter equation\n");
    gets(infix);

    printf("\n1 Infix to Postfix \n2 for Infix to Prefix \nEnter value ");
    scanf("%d",&num);
    printf("\n");
    if(num==1){
        postfix();
        printf("Postfix: ");
        for(int i=0; i<=k; i++){
            if(post[i]!='(' && post[i]!=')')
            printf("%c",post[i]);
        }
    }
    else if(num==2){
        prefix();
        printf("Prefix: ");
        for(int i=0; i<=k; i++){
            if(post[i]!='(' && post[i]!=')')
            printf("%c",post[i]);
        }
    }
    else
        printf("Enter valid number");
    printf("\n");
}