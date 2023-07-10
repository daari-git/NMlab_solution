/* Linear Regression 
prepared by:-
Subash khanal 
crn: 020-626 */
#include <stdio.h>
#include<math.h>
#include<conio.h>
// function linearRegression
void linearRegression(float x[], float y[], int n, float* slope, float* intercept) {
    float sum_x = 0, sum_y = 0, sum_xy = 0, sum_xx = 0;
    for (int i = 0; i < n; i++) {
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_xx += x[i] * x[i];
    }
    *slope = (n * sum_xy - sum_x * sum_y) / (n * sum_xx - sum_x * sum_x);
    *intercept = (sum_y - *slope * sum_x) / n;
}

int main() { 
	float x[100],y[100];
    int i,n;
	printf("Enter the number of data n:");  //number of data in question 
	scanf("%d",&n);
	for(i=0;i<n;i++)     // for x 
	{
		printf("x[%d]=",i+1);
		scanf("%f",&x[i]);
	}
	printf("Enter the value of y\n");
	for(i=0;i<n;i++)
	{
		printf("y[%d]=",i+1);
		scanf("%f",&y[i]);
	}
    float slope, intercept;
    linearRegression(x, y, n, &slope, &intercept);
    //printing slope and intercept
    printf("Intercept: %.2f\n", intercept); //intercept
    printf("Slope: %.2f\n", slope);   //slope
    printf(" Linear Regression by:-\n Subash khanal\n\n"); //Programmer details
    return 0;
    getch();
}
