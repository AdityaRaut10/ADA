#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define ll long long int
struct Node
{
    int data;
    char name[20];
    struct Node *next;
    struct Node *prev;
};
typedef struct Node node;
void swap(int* a, int* b )
{
  int t = *a;
      *a = *b;
      *b = t;
}
node *lastNode(node *root)
{
    while (root && root->next)
        root = root->next;
    return root;
}
node* partition(node *l, node *h)
{
    int x  = h->data;
    int index;
    char ch;
    node *i = l->prev;
    node *j;
    for(j = l; j != h; j = j->next)
    {
        if (j->data <= x)
        {
            i = (i == NULL)? l : i->next;

            swap(&(i->data), &(j->data));
           index=0;
             while(i->name[index] != '\0') {
                      ch = i->name[index];
                      i->name[index] = j->name[index];
                      j->name[index] = ch;
                      index++;
                   }
        }
    }
    i = (i == NULL)? l : i->next;
    swap(&(i->data), &(h->data));
    index=0;
    while(i->name[index] != '\0') {
                      ch = i->name[index];
                      i->name[index] = h->name[index];
                      h->name[index] = ch;
                      index++;
                   }
    return i;
}

void _quickSort(struct Node* l, struct Node *h)
{
    if (h != NULL && l != h && l != h->next)
    {
        struct Node *p = partition(l, h);
        _quickSort(l, p->prev);
        _quickSort(p->next, h);
    }
}
void quickSort(struct Node *head)
{
    struct Node *h = lastNode(head);
    _quickSort(head, h);
}
void printList(struct Node *head)
{
    while (head)
    {
        printf("%s  %d\n", head->name, head->data);
        head = head->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data, char nam[])
{
    node *new_node = (struct Node *)malloc(sizeof(node));
    new_node->data  = new_data;
    strcpy(new_node->name, nam);
    new_node->prev = NULL;

    new_node->next = (*head_ref);

    if ((*head_ref) !=  NULL)  (*head_ref)->prev = new_node ;

    (*head_ref)    = new_node;
}

int main()
{
    struct Node *a = NULL;
    printf("Total students : ");
    int n, i;
    scanf("%d", &n);
    int *arr;
    char str[n][20];
    arr = (int *)malloc(n*sizeof(int));
    for(i=0; i<n; i++) scanf("%s %d", str[i], &arr[i]);
    for(i=0; i<n; i++) push(&a, arr[i], str[i]);
    quickSort(a);
    printf("sorted data is :: \n");
    printList(a);
    return 0;
}
