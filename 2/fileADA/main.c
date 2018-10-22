#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main(int argc, char *argv[])
{
    //char name[20];
    //int age=0;
    //age=20;
    int i=0;
    char file1[strlen(argv[1])+4];
    char file2[strlen(argv[2])+4];
    //strcpy(file1, argv[1]);
    //strcpy(file2, argv[2]);
    for(i=0; i<strlen(argv[1]); i++)
    {
        file1[i]=argv[1][i];
    }
    file1[i++]='.';
    file1[i++]='t';
    file1[i++]='x';
    file1[i++]='t';
    for(i=0; i<strlen(argv[2]); i++)
    {
        file2[i]=argv[2][i];
    }
    file2[i++]='.';
    file2[i++]='t';
    file2[i++]='x';
    file2[i++]='t';
    FILE *fp1 = fopen(file1, "w");
    FILE *fp2 = fopen(file2, "w");
    for(i=1; i<20; i+=2) fprintf(fp1,"%d ", i);
    for(i=2; i<20; i+=2) fprintf(fp2,"%d ", i);
    fclose(fp1);
    fclose(fp2);
    int temp=0;
    fopen(file1, "a");
    fopen(file2, "a");
    int arr1[100]={0}, arr2[100]={0};
    int j=0;
   /* do
    {
        fscanf(fp1,"%d ", &temp);
        arr1[j]=temp;
        j++;
        printf("%d ", temp);
    }while(fscanf(fp1, "%d ", &temp)!=EOF);
    printf("\n");
    j=0;
    do
    {
        fscanf(fp2, "%d ",&temp);
        arr2[j]=temp;
        j++;
        printf("%d ", temp);
    }while(fscanf(fp2, "%d ", &temp)!=EOF);*/
    while(fscanf(fp1, "%d ", &temp)!=EOF)
    {
        arr1[j]=temp;
        j++;
        printf("%d ", temp);
    }
    j=0;
    while(fscanf(fp2, "%d ", &temp)!=EOF)
    {
        arr2[j]=temp;
        j++;
        printf("%d ", temp);
    }
    printf("\n");
    int n1= sizeof(arr1)/sizeof(int);
    int n2= sizeof(arr2)/sizeof(int);
    i=0;
    j=0;
    //int k=0;
    int arr[21]={0};
    /*while(i<n1 && j<n2)
    {
        if(arr1[i]<=arr2[j]){
            arr[k]=arr1[i];
            i++;
        }
        else{
            arr[k]=arr2[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
      arr[k]=arr1[i];
      i++;
      k++;
    }
    while(j<n2)
    {
     arr[k]=arr2[j];
      j++;
      k++;
    }*/
    j=0;
    for(i=0; i<n1; i++) arr[j++]=arr1[i];
    for(i=0; i<n2; i++) arr[j++]=arr2[i];
    for(i=0; i<j; i++)
        printf("%d ", arr[i]);
        printf("\n");

   /*char temp[20];
    strcpy(temp,name);
    strrev(temp);
    if(strcmp(temp, name)==0){
        printf("IT is palindrome\n");
    }
    else printf("IT is NOT palindrome\n");*/
    fclose(fp1);
    fclose(fp2);
    return 0;
}