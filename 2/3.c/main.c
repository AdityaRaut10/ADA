#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<stdbool.h>
typedef struct Node node;
struct Node{
  int c;
  node *next;
};
node *head=NULL;

void push(int data)
{
    node *NewNode = (node *)malloc(sizeof(node));
    NewNode->next=NULL;
    NewNode->c=data;
    if(head==NULL) head=NewNode;
    else
    {
        NewNode->next=head;
        head = NewNode;
    }
}
void pop()
{
    if(head==NULL) printf("stack in Empty\n");
    else{
        node *temp=head;
        head = head->next;
        free(temp);
    }
}
void display()
{
    node *temp = head;
    while(temp!=NULL)
    {
        printf("%d ", temp->c);
        temp = temp->next;
    }
}
int main()
{
    int temp=0;
    FILE *fp1 = fopen("stackInput.txt", "r");
    while(getw(fp1)!=EOF)
    {
        if(temp==1)
        {
            printf("Enter stack Elements\n");
            int num=0;
            while(num!=-1)
            {
                scanf("%d", &num);
                push(num);
            }
        }
        else if(temp==2) display();
        else pop();
    }
    return 0;
}
