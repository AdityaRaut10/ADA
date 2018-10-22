#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void wap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    if(left<n && arr[left]>arr[largest]) largest = left;
    if(right<n && arr[right]>arr[largest]) largest = right;
    if(largest!=i)
    {
        wap(&arr[largest], &arr[i]);
        heapify(arr, n, largest);
    }
}
double heapsort(int arr[], int n)
{
    clock_t beg = clock();
    int i=0;
   for(i=(n/2)-1; i>=0; i--) heapify(arr, n , i);
    for( i=n-1; i>=0; i--)
    {
        wap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
    beg = clock()-beg;
    return (double) beg/CLOCKS_PER_SEC;
}
double insertion_sort(int arr[], int n)
{
    clock_t beg = clock();
    int i, j;
    for(i=1; i<n; i++)
    {
        int hold = arr[i];
        j=i-1;
        while(j>=0 && arr[j]>hold)
        {
            arr[j+1]= arr[j];
            j--;
        }
        arr[j+1]=hold;
    }
    beg = clock()-beg;
    return (double) beg/CLOCKS_PER_SEC;
}
void merge(int arr[], int l, int m, int r)
{
    int n1 = m-l+1, n2 = r-m;
    int a[n1], b[n2];
    int i,j,k;
    for(i=0; i<n1; i++) a[i]=arr[l+i];
    for(j=0; j<n2; j++) b[j]=arr[m+1+j];
    i=0;
    j=0;
    k=l;
    while(i<n1 && j<n2)
    {
        if(a[i]<=b[j]){
            arr[k] = a[i];
            i++;
        }
        else {
            arr[k]=b[j];
            j++;
        }
        k++;
    }
    while(i<n1) arr[k++]=a[i++];
    while(j<n2) arr[k++]=b[j++];
}
double mergesort(int arr[], int l, int r)
{
    clock_t beg = clock();
    if(l<r)
    {
        int m = (l+r)/2;
        mergesort(arr, l, m);
        mergesort(arr, m+1, r);
        merge(arr, l, m, r);
    }
    beg = clock()-beg;
    return (double) beg/CLOCKS_PER_SEC;
}
double selection_sort(int arr[], int n)
{
    int i, j;
    clock_t beg = clock();
    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(arr[j]<arr[i])
            {
                int c = arr[j];
                arr[j]=arr[i];
                arr[i]=c;
            }
        }
    }
    beg = clock()-beg;
    return (double) beg/CLOCKS_PER_SEC;
}
double bubble_sort(int arr[], int n)
{
    int i, j;
    clock_t beg = clock();
    for(i=0; i<n; i++)
    {
        for(j=0; j<n-1-i; j++)
        {
            if(arr[j+1]<arr[j])
            {
                int c = arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=c;
            }
        }
    }
    beg = clock()-beg;
    return beg/CLOCKS_PER_SEC;
}
int main(int argc, char *argv[])
{
    srand(time(0));
    double tim;
    int i=0;
    int n;
    n = atoi(argv[1]);
    int *arr;
    arr = (int *)malloc(n*sizeof(int));
    for(i=0; i<n; i++)  arr[i] = 1+rand()%1000;
    tim = insertion_sort(arr, n);
    printf("Insertion sort :: %lf\n", tim);
    //for(i=0; i<n; i++) printf("%d ", arr[i]);
    printf("\n");
    for(i=0; i<n; i++)  arr[i] = 1+rand()%1000;
    tim = mergesort(arr, 0, n-1);
    printf("merge sort sort :: %lf\n", tim);
    //for(i=0; i<n; i++) printf("%d ", arr[i]);
    printf("\n");
    for(i=0; i<n; i++)  arr[i] = 1+rand()%1000;
    tim = heapsort(arr, n);
    printf("heap sort sort :: %lf\n", tim);
    //for(i=0; i<n; i++) printf("%d ", arr[i]);
    printf("\n");
    for(i=0; i<n; i++)  arr[i] = 1+rand()%1000;
    tim = selection_sort(arr, n);
    printf("selection sort sort :: %lf\n", tim);
    //for(i=0; i<n; i++) printf("%d ", arr[i]);
    return 0;
}
