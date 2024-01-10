#include<stdio.h>
//  Quick_sort
// int arr[] = {34,45,67,12,7,32,2,543};
int arr[] = {10,5,-4,3,96,2,98,-88};
void display(int size){
    for (int i = 0; i < size; i++){
        printf("%d, ",arr[i]);
    }
    printf("\n");
}

int sort(int pivot, int start, int end){
    int i,j=0,k,swap;
    int size = sizeof(arr)/sizeof(arr[0]);
    k=3;
    while (k>0)
    {
        start = pivot;
        // printf("\nstart=%d, end=%d",start,end);
        for (i = end; i >= start; i--){
            j++;
            // printf("---arr[pivot]=%d, arr[i]=%d",arr[pivot],arr[i]);
            if (arr[pivot]>arr[i]){
                swap = arr[pivot];
                arr[pivot] = arr[i];
                arr[i] = swap;
                pivot = i;
                break;
            }
        }
        start++;
        // printf("\nstart=%d, end=%d",start,end);
        end = pivot;
        j=0;
        for (i = start; i < end; i++){
            start = pivot;
            if (arr[pivot]<arr[i]){
                j++;
                swap = arr[pivot];
                arr[pivot] = arr[i];
                arr[i] = swap;
                pivot = i;
                break;
            }
        }
        end --;
        // printf("\nstart=%d, end=%d, pivot=%d\n",start,end,pivot);
        k--;
    }
    // for (int i = 0; i < size; i++)
    // {
    //     printf("%d, ",arr[i]);
    // }
    // printf("--------------\n");
    return pivot;
}

void quick_sort(int start, int end){
    int pivot;
    if (start<end){
        pivot = start;
        pivot = sort(pivot, start, end);
        quick_sort(start, pivot-1);
        quick_sort(pivot+1, end);
    }
}

void main(){
    int size;
    size = sizeof(arr)/sizeof(arr[0]);
    printf("Entered Array: ");
    display(size);
    quick_sort(0, size-1);
    printf("Sorted Array: ");
    display(size);
    printf("\n");
}