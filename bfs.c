#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
	int info,c,d;
	struct node *f,*r;
}nd;


void insert(nd **);
void insert1(nd **,int );
void bfs(nd **);
void bfs1(nd **);

int main()
{
	nd *l=NULL,*r=NULL;
    int n,i;
    printf("Enter no. of vertices :- ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
    	insert(&r);
    	if(i==0)
    	l=r;
	}
	insert1(&l,n);
    bfs(&l);
}

void insert(nd **r)
{
    nd *p;
    int x,n,i;
    p=(nd*)malloc(sizeof(nd));
    printf("enter vertex name :");
    scanf("%d",&x);
    p->info=x;p->c=p->d=0;
    p->f=NULL;p->r=NULL;
    if((*r)!=NULL)
    (*r)->f=p;
    (*r)=p;
}

void insert1(nd **r,int n)
{
    int a[n][n],i,j;
    nd *t=NULL,*t1=NULL;
    nd *t2=(*r);
    printf("Enter 1 for Yes    and     2 for no\n");
    for(i=0;i<n;i++)
    {
    	nd *p=(*r);j=0;
		while(p!=NULL)
    	{
    	   if(p->info!=t2->info)
    	   {printf("is there any edge b/w %d and %d :- ",t2->info,p->info);
    	   scanf("%d",&a[i][j]);
    	   if(a[i][j]==1)
    	   {
    	   	t=(nd*)malloc(sizeof(nd));		
            t->info=p->info;t->f=t->r=NULL;
            if(t2->r==NULL)
            {t1=t;t2->r=t;}
            else
           {t1->r=t;
           t1=t;
	       }
	       t1->f=p;
		   }
		   }
		   j++;
		   p=p->f;
		}
		t2=t2->f;
	}
	
}


void bfs(nd **l)
{
	if((*l)!=NULL&&(*l)->d!=1)
	{
        bfs1(l);
		nd *t=(*l)->r;
		while(t!=NULL)
		{
			nd *p=t->f;
			bfs1(&p);
			t=t->r;
		}
		(*l)->d=1;
		(*l)=(*l)->f;
		bfs(l);
	}
}

void bfs1(nd **l)
{
	if((*l)->c!=1)
			{
				printf("%d ",(*l)->info);
			    (*l)->c=1;
			}
}

