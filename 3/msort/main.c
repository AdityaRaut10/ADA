#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<time.h>
#define ll int
void merge(ll arr[], ll l, ll m, ll r)
{
    ll i, j, k=0;
    ll n1 = m-l+1;
    ll n2 = r-m;
    ll a[n1], b[n2];
    for(i=0; i<n1; i++) a[i]=arr[l+i];
    for(j=0; j<n2; j++) b[j]=arr[m+1+j];
    i=0;
    j=0;
    k=l;
    while(i<n1 && j<n2)
    {
        if(a[i]<=b[j])
        {
            arr[k]=a[i];
            i++;
        }
        else
        {
            arr[k]=b[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        arr[k]=a[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k]=b[j];
        j++;
        k++;
    }
}
void mergesort(ll arr[], ll l , ll r)
{
    if(l<r)
    {
        ll m = (l+r)/2;
        mergesort(arr, l, m);
        mergesort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}
int main(int argc, char *argv[])
{
    srand(time(NULL));
    ll i=0;
    ll *arr;
     clock_t t =clock();
    ll n = atoi(argv[1]);
    arr = (ll*)malloc((n+1)*sizeof(arr));
    for( i=0; i<n; i++)
    {
        arr[i]=1+rand()%100000;
    }
    mergesort(arr, 0, n);

    for(i=0; i<n; i++) printf("%d ", arr[i]);
    t = clock()-t;
    printf("\n");
    printf("TIME :: %0.9lf", (double)(t)/CLOCKS_PER_SEC);
    return 0;
}
