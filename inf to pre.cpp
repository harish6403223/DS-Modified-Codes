#include<stdio.h>
#include<ctype.h>
#include<string.h>

void func(char a[],char b[],int *i,int *w)
{
	char c[100]={0},ct=-1;
	while(a[(*i)]!=0)
	{
	  if(isdigit(a[*i]))
	  {
	  	b[(*w)]=a[(*i)];
	  	(*i)--;(*w)--;
	  	if(a[(*i)]=='^')
	  	{
	  		b[(*w)]=a[(*i)-1];(*w)--;
	  		b[(*w)]=a[(*i)];(*w)--;(*i)=(*i)-2;
		}
	  }
	  else if(a[*i]==')')
	  {
	  	(*i)--;
	     func(a,b,i,w);
	  }
	  else if(a[*i]=='(')
	  {
	  	(*i)--;
	  	while(ct>=0)
	{
		b[(*w)]=c[ct];(*w)--;ct--;
	}
	     return;
	  }             
	  else
	  {
	  	if((a[(*i)]=='+'||a[(*i)]=='-'))
	  	{
		  	while(ct>-1&&!(c[ct]=='+'||c[ct]=='-'))
		  	{
		  		b[(*w)]=c[ct];(*w)--;ct--;
			  }
			  ct++;c[ct]=a[(*i)];
	  	      (*i)--;
		  }
		  else
		  {
		  	ct++;
		  	c[ct]=a[(*i)];
			  (*i)--;
		  }
	  }
	}
	while(ct>=0)
	{
		b[(*w)]=c[ct];(*w)--;ct--;
	}
}

int main()
{
	char a[100],b[100];
	scanf("%s",a);
	int i,w,c=0;
	for(i=0;i<strlen(a);i++)
	{
		if(a[i]=='(')
		  c+=2;
	}
	i=strlen(a)-1,w=strlen(a)-1-c;
	func(a,b,&i,&w);
	b[strlen(a)-c]=0;
	printf("%s",b);
}

