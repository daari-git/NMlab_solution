/* finding the root of non-linear question
prepared by:-
Subash khanal 
crn: 020-626 */

#include<stdio.h>
#include<conio.h>
#include<math.h>
float f(float x)
{
    return(2*exp(-x)-sin(x)); // defining the function 
}
int main()
{
    float x0,x1,x2,d,e;
    int count=1,n;
    // programmer details 
    printf("Secant Method prepared by:-\n Subash khanal\n\n");
    // guessing intial values taking from user 
    printf("Enter the values of a and b:\n");  
    scanf("%f%f",&x0,&x1);
    // for error taking from user 
    printf("Enter the values of allowed error \n"); 
    scanf("%f",&e);
    // for the maximum number of iteration taking from user 
    printf("Enter the maximun number of iterations:\n");
    scanf("%d",&n);
    // for the tabuar form.
    printf("Iteration\t  x0\t\t\t x1\t\t\t x2\n"); 
    do
    {
        if(f(x0)==f(x1))
        {
            printf("\nSolution cannot be found as the values of a and b are same.\n");
        return 0;
        }
        // formula for secant method
        x2=(x0*f(x1)-x1*f(x0))/(f(x1)-f(x0)); 
        x0=x1;
        x1=x2;
        printf("%d\t     %f\t\t     %f\t\t    %f\n",count,x0,x1,x2);
        count++;
        if(count==n)
        {
        break;
        }
    } while(fabs(f(x2))>e);
    // printing the required solution 
    printf("\n The required solution is %f\n",x2);

}
