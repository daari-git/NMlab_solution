/* Lagrange Interpolation
prepared by:-
Subash khanal 
crn: 020-626 */
#include<stdio.h>
#include<conio.h>

int main()
{
	 // programmer details 
    printf("Lagrange Interpolation by:-\n Subash khanal\n\n");
    
	 float x[100], f[100], x0, sum=0, product;
	 int i,j,n;
	 // Number of datasheets that is given in question
	 printf("Enter number of data: ");
	 scanf("%d", &n);
	 printf("Enter data:\n");
	 //taking data from user one by one 
	 for(i=1;i<=n;i++)
	 {
		printf("Enter the value of x[%d] = ", i);
		scanf("%f", &x[i]);
		printf("Enter the value of f[%d] = ", i);
		scanf("%f", &f[i]);
	 }
	 // asking to user for interpolation point 
	 printf("Enter interpolation point: ");
	 scanf("%f", &x0);
	 for(i=1;i<=n;i++)
	 {
		  product=1;
		  for(j=1;j<=n;j++)
		  {
			   if(i!=j)  // condition 
			   {
			    	product = product* (x0 - x[j])/(x[i] - x[j]);
			   }
		  }
		  sum = sum + product * f[i];
	 }
	 //Result.
	 printf("\n\nInterpolated value at %.3f is %.3f.", x0, sum);
	 getch();
}
