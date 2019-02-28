/*Name: P HARISH KUMAR
  Sec : A
  Roll no: 52
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int info,j,sm;
    struct node *next;
}nd;

void insert(nd** ,int );
void serve(nd** ,nd** );
void display(nd* ,nd* );

int main()
{
    int n,s=0;
    nd *l=NULL,*r=NULL;
    do
    {
        printf("enter choice\n");
        printf("1 for insert\n0 for exit\n");
        scanf("%d",&n);
        switch(n)
        {
        case 1:s++;
            insert(&r,s);
            if(l==NULL)
                l=r;
                r->next=l;
            break;
        case 0:
            continue;
        default:
            printf("invalid choice\n");
        }
    }while(n!=0);
    display(l,r);
}

void insert(nd** r,int f)
{
    nd *p;
    int x;
    p=(nd* )malloc(sizeof(nd));
    printf("enter node time : ");
    scanf("%d",&x);
    p->info=x;
    p->j=f;
    p->sm=0;
    p->next=NULL;
    if((*r)!=NULL)
        (*r)->next=p;
    *r=p;
}

void serve(nd** r,nd** l)
{
    printf("node name: %d\nweight of node: %d\n\n",(*l)->j,(*l)->sm);
    nd *o=(*l);
    (*l)=(*l)->next;
    (*r)->next=(*l);
    free(o);
}


void display(nd* l1,nd* r1)
{
   int n=0,sum=0;
   while(l1->next!=l1)
   {
       n++;
       if(l1->info<10)
       {
          n--;sum=sum+l1->info;
       }
       l1->info=l1->info-10;
            l1->sm=10*(n)+sum;
    if(l1->info<=0)
        serve(&r1,&l1);
    else
       {
           r1=l1;l1=l1->next;
       }

   }
   printf("node name: %d\nweight of node: %d\n\n",l1->j,(l1->info+n*10+sum));
}
