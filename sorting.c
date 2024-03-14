#include <stdio.h>
#define MAX 100

int countcompare = 0;
int exhngcount = 0;
int i;
void merge(int array[], int start, int middle, int end)
{
    int i = start;
    int j = middle + 1;
    int k = start;
    int b[MAX];
    while (i <= middle && j <= end)
    {
        if (array[i] < array[j])
        {
            b[k] = array[i];
            i++;
            exhngcount++;
        }
        else
        {
            b[k] = array[j];
            j++;
        }
        k++;
        countcompare++;
        exhngcount++;
    }
    while (i <= middle)
    {
        b[k] = array[i];
        i++;
        k++;
        exhngcount++;
    }
    while (j < end)
    {
        b[k] = array[j];
        j++;
        k++;
        exhngcount++;
    }
    for (i = start; i < k; i++)
    {
        array[i] = b[i];
        exhngcount++;
    }
    exhngcount++;
}
void mergesort(int array[], int start, int end)
{
    if (start < end)
    {
        int middle = (start + end) / 2;
        mergesort(array, start, middle);
        mergesort(array, middle + 1, end);
        merge(array, start, middle, end);
        countcompare++;
    }
    exhngcount++;
}
int main()
{
    int array[MAX];
    int n;
    printf("Enter the size of an array: ");
    scanf("%d", &n);
     printf("Enter the element  of an array");
    for ( i = 0; i < n; i++)
    {

        scanf("%d", &array[i]);
    }
    mergesort(array, 0, n - 1);
    printf("Sorted array : ");
    for ( i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\nNo of Comparsions: %d", countcompare);
    printf("\nNo of Exchanges: %d", exhngcount);
    
}


