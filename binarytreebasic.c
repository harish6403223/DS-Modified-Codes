#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int info;
    struct node *f,*r;
}nd;

void insert(nd** );
void del(nd** );
void display1(nd* );
void display2(nd* );
void display3(nd* );

int main()
{
    int n;
    nd *l=NULL;
    do
    {
        printf("enter choice\n");
        printf("1 for insert\n2 for delete\n3 for display\n0 for exit\n");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            insert(&l);
            break;
        case 2:
		      if(l==NULL)
		      printf("overflow\n");
		      else
		      del(&l);
		      break;
        case 3:
             if(l==NULL)
              printf("empty\n");
             else
                {
                    printf("\n\nFor preorder: ");
                    display1(l);
                    printf("\n\nFor inorder: ");
                    display2(l);
                    printf("\n\nFor postorder: ");
                    display3(l);
                    printf("\n\n");
                }
            break;
        case 0:
            continue;
        default:
            printf("invalid choice\n");
        }
    }while(n!=0);
}

void insert(nd** l)
{
    nd *p,*t=(*l);
    int x;
    p=(nd* )malloc(sizeof(nd));
    printf("enter no. to insert: ");
    scanf("%d",&x);
    p->info=x;
    p->f=p->r=NULL;
    if((*l)==NULL)
        (*l)=p;
    else
    {
        while(1)
        {
            if(p->info<t->info)
            {
                if(t->f==NULL)
                    {
                        t->f=p;
                        break;
                    }
                else
                    t=t->f;
            }
            else
            {
                if(t->r==NULL)
                    {
                        t->r=p;
                        break;
                    }
                else
                    t=t->r;
            }
        }
    }
}

void del(nd** l)
{
	nd (*ft)=NULL,(*t)=(*l);
	int f1=0,k;
	printf("Enter key to delete :- ");
	scanf("%d",&k);
	while(t!=NULL)
	{
		if(t->info==k)
		{
			f1=1;
			break;
		}
		else
		{
			if((t->info)<k)
			{
				ft=t;
				t=t->r;
			}
			else
			{
				ft=t;
				t=t->f;
			}
		}
	}
	if(f1!=1)
	printf("Not found\n");
	else
	{
		printf("Found\n");
		nd *r=t->r,*f=t->f;
		if(r!=NULL)
		{
			if(ft!=NULL)
			{
				if(ft->f==t)
				ft->f=r;
				else
				ft->r=r;
			}
			else
			(*l)=r;
			while(r->f!=NULL)
			r=r->f;
			r->f=f;
		}
		else
		{
			if(ft!=NULL)
			{
				if(ft->f==t)
				ft->f=f;
				else
				ft->r=f;
			}
			else
			(*l)=f;
		}
		free(t);
	}
}

void display1(nd* l)
{
        if(l!=NULL)
		{
		printf("%d ",l->info);
            display1(l->f);
            display1(l->r);
		}
}

void display2(nd* l)
{
        if(l!=NULL)
		{
            display2(l->f);
            printf("%d ",l->info);
            display2(l->r);
		}
}

void display3(nd* l)
{
        if(l!=NULL)
		{
            display3(l->f);
            display3(l->r);
            printf("%d ",l->info);
		}
}
