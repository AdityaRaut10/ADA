
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[])
{
    int i=0, j=0, dum;
    int arr[10]={0};
    char n1[10]="", n2[10]="";
    strcpy(n1, argv[1]);
    strcpy(n2, argv[2]);
    FILE *fp1=fopen(n1, "w");
    FILE *fp2=fopen(n2, "w");
    if(!fp1 || !fp2){
      printf("Error!!");
      exit(1);
    }
    for(i=1; i<=5; i++) fprintf(fp1, "%d ", i);
    for(i=6; i<=10; i++) fprintf(fp2, "%d ", i);
    fclose(fp1);
    fclose(fp2);
    fopen(n1, "r");
    fopen(n2, "r");
    while(fscanf(fp1, "%d ", &dum)!=EOF) arr[j++]=dum;
    while(fscanf(fp2, "%d ", &dum)!=EOF) arr[j++]=dum;
    for(i=0; i<10; i++) printf("%d ", arr[i]);
    FILE *fp3=fopen("copy.txt", "w");
    for(i=0; i<10; i++)
    {
        fprintf(fp3, "%d ", arr[i]);
    }
    fclose(fp3);
    return 0;
}
