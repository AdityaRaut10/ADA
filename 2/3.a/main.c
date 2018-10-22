#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<stdbool.h>
int main(int argc, char *argv[])
{
    bool is_pal=true;
    int i=0;
    char n1[10]="", n2[20]="", temp[20]="";
    strcpy(n1, argv[1]);
    strcpy(n2, argv[2]);
    FILE *fp1=fopen(n1, "w");
    fprintf(fp1, "%s", n2);
    fclose(fp1);
    fopen(n1, "r");
    fgets(temp, 20, fp1);
    int len = strlen(temp);
    for(i=0; i<=len/2; i++)
    {
        if(temp[i]!=temp[len-1-i]) {
                is_pal=false;
                break;
        }
    }
    if(is_pal) printf("It is a palindrome\n");
    else printf("Not a palindrome\n");
    return 0;
}
