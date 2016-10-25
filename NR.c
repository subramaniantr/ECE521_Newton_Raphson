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
     return(1E-3 - 1E-16*(exp(40*x) - 1.0));   
     }
else
   if(op == '4')
    {
     return((1/x) - 3.1415);   
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
else
   if(op == '4')
    {
     return(-1/(x*x));   
     }
}



void main()
{
double x, x_prev,dx, abstol,reltol,k,tol;
int i;
char option;
        system("clear");
        printf("Enter your function option :   \n");
        printf("Enter 1 for function : x^2-1     \n");
        printf("Enter 2 for function : x^2   \n");
        printf("Enter 3 for function : 10^(-3) - 10^(-16)[exp(40x)-1]\n");
        printf("Enter 4 for function : 1/pi\n");
        printf("Enter any other key to exit \n");
        scanf("%s", &option);
        if(option == '1' || option =='2' || option =='3' || option =='4')
       {
        printf("Please enter the starting point : ");
        scanf("%lf",&x );
   //     printf("Please enter the tolerance : ");
   //     scanf("%lf",&tol );
        i = 1;
        x_prev=0;
        dx = 100;
        tol = 0;
        abstol = 1e-6;
        reltol = 1e-3;
        while(dx>tol)
        {
            x_prev = x;                         //assign x_prev to current x
            x = x - f(x,option)/df(x,option);   //Update the new x based on NR algorithm
            dx = fabs(x-x_prev);                //FIND dx
            printf(" At Iteration no. %3d, x = %9.6f, x_prev = %9.6f, dx = %9.6f \n", i, x, x_prev, dx);
 //BREAK THE LOOP IF NUMBER OF ITERATIONS EXCEED 100
         if(i==100)
            {
              printf("Exited without Convergence after 100 iterations\n\n\n");
              break;
            }
         i++;
             k=(fabs(x)>fabs(x_prev))?fabs(x):fabs(x_prev);        //Find max(|x|,|x_prev|)
            tol= abstol + reltol*k;        //Calculation of tol
        }//END OF NEWTON'S LOOP   
       }
 
else
    {
     printf("EXITED \n");
     }

}
