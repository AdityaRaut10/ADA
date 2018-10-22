#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int n;
int cou=0;
void print(int arr[n][n])
{
    int i, j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(arr[i][j]==0) printf(".  ");
            else printf("X  ");
        }
        printf("\n");
    }
     printf("\n");
}
bool is_possible(int arr[n][n], int row, int col)
{
    int i, j;
    for(i=0; i<col; i++)
    {
        if(arr[row][i]==1) return false;
    }
    for(i=row, j=col; i>=0 && j>=0; i--, j--)
    {
        if(arr[i][j]) return false;
    }
    for(i=row, j=col; i<n && j>=0; i++, j--)
    {
        if(arr[i][j]) return false;
    }
    return true;
}
bool solve(int arr[n][n], int col)
{
    if(col>=n){
      //printf("%d - \n", ++cou);
      //print(arr);
      ++cou;
    }
    int i;
    for(i=0; i<n; i++)
    {
        if(is_possible(arr, i, col))
        {
            arr[i][col]=1;
            if(solve(arr, col+1)) return true;

            arr[i][col]=0;
        }

    }
    return false;
}
int main()
{
    int siz, i, j;
    //scanf("%d", &siz);

    //n = siz;
    /*for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            arr[i][j]=0;
    }
    solve(arr, 0);*/
    for(siz=1; siz<=14; siz++)
    {
        cou=0;
        n = siz;
        int arr[n][n];
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++) arr[i][j]=0;
        }
        solve(arr, 0);
        printf("%d  -  %d\n", siz, cou);
    }
    return 0;
}
