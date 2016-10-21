#include <stdio.h>
#include <math.h>

double f(double x, char op)
{
   if(op == '1')
   {
    return(x*x-1.0);
   }

else

  if(op == '2')
    {
     return(x*x);
    }
else
   if(op == '3')
    {
     return(10E-3 - 1E-16*(exp(40*x) - 1.0));   
     }

}



double df(double x, char op)
{
 
   if(op == '1' || op == '2')
   {
    return(2*x);
   }
else 
   if(op == '3')
   {
   return(-40E-16*(exp(40*x)));
    }
}



void main()
{
double x, x_prev,dx, tol;
int i;
char option;
        system("clear");
        printf("Enter your function option :   \n");
        printf("Enter 1 for function : x^2-1     \n");
        printf("Enter 2 for function : x^2   \n");
        printf("Enter 3 for function : 10^(-3) - 10^(-16)[exp(40x)-1]\n");
        printf("Enter any other key to exit \n");
        scanf("%s", &option);
        if(option == '1' || option =='2' || option =='3')
       {
        printf("Please enter the starting point : ");
        scanf("%lf",&x );
        printf("Please enter the tolerance : ");
        scanf("%lf",&tol );
        i = 1;
        x_prev=0;
        dx = fabs(x-x_prev);
        while(dx>tol)
        {
            x_prev = x;           //save the previous x
            x = x - f(x,option)/df(x,option);   //Update the new x
            dx = fabs(x-x_prev);
            printf(" At Iteration no. %3d, x = %9.6f, x_prev = %9.6f, dx = %9.6f \n", i, x, x_prev, dx);
         
         i++;
        }   
       }
 
else
    {
     printf("EXITED \n");
     }

}
