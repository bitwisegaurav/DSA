#include <stdio.h>
// Sorting Array (ascending order)
int main(){
    int arr[6],low,a[6]={0},k;
    
    for(int i=0;i<6;i++){
        printf("Enter number ");
        scanf("%d",&arr[i]);
    }
    printf("\nYour entered array is [ ");
    for(int i=0;i<6;i++){
            printf("%d, ",arr[i]);
    }
    printf("] \n\nArray in ascending order is [ ");
    for(int i=0;i<6;i++){
        low = arr[i];
        for(int j=0; j<6; j++){
            if(low>=arr[j]){
                low = arr[j];
                k = j;
            }
        }
        arr[k]=32767;
        a[i] = low;
    }
    for(int j=0;j<6;j++){  printf("%d, ",a[j]);  }
    printf("]");
    
    return 0;
}