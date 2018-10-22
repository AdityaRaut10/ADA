#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int mx(int a, int b)
{
    return (a>b)?a:b;
}
int lcs(char x[], char y[], int m, int n)
{

    if(m==0 || n==0) return 0;

    if(x[m-1]==y[n-1]) return 1+lcs(x, y, m-1, n-1);
     return mx(lcs(x, y, m-1, n), lcs(x, y, m, n-1));
}
int main()
{

    char x[50], y[50];
    int m, n, i, j;

    scanf("%s %s", x, y);
    m = strlen(x);
    n = strlen(y);
    int  board[m+1][n+1];
    for(i=0; i<=m; i++) for(j=0; j<=n; j++) board[i][j]=0;
    clock_t beg1 = clock();
    for(i=0; i<=m; i++)
    {
        for(j=0; j<=n; j++)
        {
            if(i==0 || j==0) board[i][j]=0;
            else if(x[i-1]==y[j-1])
            {
                board[i][j]=1+board[i-1][j-1];
            }
            else board[i][j] = mx(board[i-1][j], board[i][j-1]);
        }
    }
    printf("Complexity  LengthofLCS  Time\n");
    beg1 = clock()-beg1;
    printf("O(m*n)           %d      %lf\n", board[m][n], (double)beg1/CLOCKS_PER_SEC);
    clock_t beg2 = clock();
    int rec = lcs(x, y, m, n);
    beg2 = clock()-beg2;
    printf("O(2^n)           %d      %lf\n",rec, (double)beg2/CLOCKS_PER_SEC);

    i = m;
    j = n;
    int k = board[m][n]-1;
    char str[k+1];
    while(i>0 && j>0)
    {
        if(x[i-1]==y[j-1])
        {
            str[k] = x[i-1];
            k--;
            i--;
            j--;
        }
        else if(board[i-1][j]>board[i][j-1]) i--;
        else j--;
    }
    for(i=0; i<board[m][n]; i++) printf("%c", str[i]);
    printf("\n");
    return 0;
}