#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
int main(int argc, char *argv[])
{
    char n1[10]="", n2[10]="";
    strcpy(n1, argv[1]);
    strcpy(n2, argv[2]);
    FILE *fp1=fopen(n1, "w");
    FILE *fp2=fopen(n2, "w");
    if(!fp1 || !fp2){
      printf("Error!!");
      exit(1);
    }
    //
    char name[] = "aditya raut", mis[]= "111715004";
    char temp[40]="";
    fprintf(fp1, "%s %s", name, mis);
    fclose(fp2);
    fclose(fp1);
    fopen(n1, "r");
    fopen(n2, "w");
    while(fgets(temp, 40, fp1))
    {
        fprintf(fp2, "%s",temp);
        printf("%s", temp);
    }
    return 0;
}
