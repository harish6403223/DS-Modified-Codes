#include<stdio.h>
int main()
{
 int n,i;
 printf("\t\t*****INPUT*****\n");
 printf("Enter the limit of numbers : ");
 scanf("%d",&n); 
 int x,a[n],sum_even=0,sum_odd=0;
 printf("Enter the numbers :\n");
 for(i=0;i<n;i++)
 {
  scanf("%d",&a[i]);
 }
 for(i=0;i<n;i++)
 {
  if(a[i]%2==0)
    sum_even+=a[i];
  else
    sum_odd+=a[i];
 }
 printf("\t\t*****OUTPUT*****\n");
 x=fork();
 if(x==0)
 {
  printf("Sum of odd numbers = %d\n",sum_odd);
 }
 else
 {
  printf("Sum of even numbers = %d\n",sum_even);
 }
 return 0;
}
