#include<stdio.h>
#include<ctype.h>

void func(char a[],char b[],int *i,int *w)
{
	char c=0,d=0,e=0;
	while(a[(*i)]!=0)
	{
	  if(isdigit(a[*i]))
	  {
	  	b[(*w)]=a[(*i)];
	  	(*i)++;(*w)++;
	  	if(a[(*i)]=='^')
	  	{
	  		b[(*w)]=a[(*i)+1];(*w)++;
	  		b[(*w)]=a[(*i)];(*w)++;(*i)=(*i)+2;
		}
	  	if(c!=0)
	  	{
	  		b[(*w)]=c;
	  		(*w)++;c=0;
		  }
	    if(d!=0&&c==0&&!(a[(*i)]=='*'||a[(*i)]=='/'||a[(*i)]=='%'))
	    {
	    	b[(*w)]=d;
	    	(*w)++;d=0;
		}
	  }
	  else if(a[*i]=='(')
	  {
	  	(*i)++;
	     func(a,b,i,w);
	  }
	  else if(a[*i]==')')
	  {
	  	(*i)++;
	     return;
	  }
	  else
	  {
	  	if((a[(*i)]!='+'&&a[(*i)]!='-'))
	  	{
		  	c=a[(*i)];
			  (*i)++;
		  }
		  else
		  {
		  	d=a[(*i)];
			  (*i)++;
		  }
	  }
	}
}

int main()
{
	char a[100],b[200];
	scanf("%s",a);
	int i=0,w=0;
	func(a,b,&i,&w);
	printf("%s",b);
}

