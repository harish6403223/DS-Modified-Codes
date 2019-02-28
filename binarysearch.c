#include<stdio.h>
int bn(int [],int );
int main()
{
    int i,a[50],n;
    printf("enter size: ");
    scanf("%d",&n);
    printf("enter elements\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    if(bn(a,n-1)==1)
        printf("found\n");
    else
        printf("not found\n");
}

int bn(int a[],int l)
{
    int f=0,k,s;
    printf("enter no. to search: ");
    scanf("%d",&s);
    while(f<=l)
    {
        k=(f+l)/2;
        if(s==a[k])
            return 1;
        else if(s<a[k])
            l=k-1;
        else
            f=k+1;
    }
    return 0;

}
