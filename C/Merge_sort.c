#include<stdio.h>
//  Merge Sort
int arr[] = {2,6,8,1,94,58,13,4};
void display(int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d, ",arr[i]);
    }
    printf("\n");
}

void merge(int center, int start, int end){
    int i,j,k,b[100];
    i=start;
    j=center+1;
    k=start;
    while (i<=center && j<=end)
    {
        if (arr[i] < arr[j])
        {
            b[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            b[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i<=center)
    {
        b[k] = arr[i];
        i++;
        k++;
    }
    while (j<=end)
    {
        b[k] = arr[j];
        j++;
        k++;
    }
    for (int i = start; i <= end; i++)
    {
        arr[i] = b[i];
        // printf("%d, ",b[i]);
    }
    // printf("\n");
}

void sort(int start, int end){
    int center;
    if (start<end){
        center = (start+end)/2;
        // printf("--%d, %d, %d--\n",center,start,end);
        sort(start, center);
        sort(center+1, end);
        merge(center, start, end);
    }
}

void main()
{
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Entered Array: ");
    display(size);
    sort(0, size-1);
    printf("Sorted Array: ");
    display(size);
    printf("\n");
}