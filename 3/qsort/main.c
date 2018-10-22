#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<time.h>
#define ll long long int
void swap(ll* a, ll* b)
{
    ll t = *a;
    *a = *b;
    *b = t;
}
ll partition (ll arr[], ll low, ll high)
{
    ll pivot = arr[high];
    ll i = (low - 1), j;
    for (j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(ll arr[], ll low, ll high)
{
    if (low < high)
    {
        ll pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int main(int argc, char *argv[])
{
    srand(time(NULL));
    ll i=0;
     clock_t t =clock();
    ll n = atoi(argv[1]);
    ll arr[n+1];
    printf("QuickSort : \n");
    for( i=0; i<n; i++)
    {
        arr[i]=1+rand()%10000000;
    }
    quickSort(arr, 0, n);
    // for(i=0; i<n; i++) printf("%lld ", arr[i]);
    t = clock()-t;
    printf("\n");
    printf("TIME :: %0.9lf", (double)(t)/CLOCKS_PER_SEC);
    return 0;
}
