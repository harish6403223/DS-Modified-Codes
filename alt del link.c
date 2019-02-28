#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int info;
    struct node *next;
}ND;
void insert(ND **);
void  del(ND **);
void dis(ND *);
int main()
{
    ND *l=NULL,*r=NULL;
    int n;
    do
    {
        printf("enter choice: \n");
        printf("1 for insert\n0 for exit\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
                  insert(&r);
                  if(l==NULL)
                  l=r;
                  break;
             case 0:continue;
             default:printf("invalid choice\n\n");
        }
    }while(n!=0);
    if(l!=NULL)
    del(&l);
    dis(l);
}

void insert(ND **r)
{
    ND *p;
    int x;
    p=(ND*)malloc(sizeof(ND));
    printf("enter no. :");
    scanf("%d",&x);
    p->info=x;
    p->next=NULL;
    if((*r)!=NULL)
    (*r)->next=p;
    (*r)=p;
	}

void  del(ND **l)
{
    ND *p=(*l);
    while(p!=NULL&&p->next!=NULL)
    {
    	ND *t=p->next;
    	p->next=(p->next)->next;
    	p=(p->next);
    	free(t);
	}
}

void dis(ND *l1)
{
    if(l1==NULL)
    printf("empty\n");
    else
    {
        while(l1!=NULL)
        {
            printf("%d ",l1->info);
            l1=l1->next;
        }
    }
    printf("\n\n");
}


