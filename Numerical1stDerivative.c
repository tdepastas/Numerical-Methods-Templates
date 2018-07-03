/* This is a programing template for numerical evaluation of a derivative of a
certain function at a particular point. Just write the function formula in
the variable y[i], put the initial values for x0 (point of calculation for
the derivative), N(size of x's grid), J(nubmer of differences taken into account,
 make ti larger for better accuracy), and h (distance of x's grid, make it lower
for better accuracy), compile it and get your results.*/
/* This is an open Source Code,
 Redistribute it as you wish,
 Creator: tdepastas, 2018
 */
#include <stdio.h>
#include <math.h>
#define ERROR -1

double x0=-2.0;//Modify point of evaluation for the derivative
int N=10;//Modify max grid element Xn
int J=2;//Modify accuracy
double h=0.1;//Modify grid distance
double x[],y[];

double kDiff(int ,int ,double *), NumDerivative1(int ,double ,double *,int );
void funcDef(double *,double *),gridDef(double *,double ,double ,int );


int main()
{
    int i;
    gridDef(x,x0,h,N);
    funcDef(y,x);
    printf("X's Grid:\n");
    for(i=0;i<N;++i)
        printf("%lf,",x[i]);
    printf("\nFunction Grid:\n");
    for(i=0;i<N;++i)
        printf("%lf,",y[i]);
    printf("\n1st Derivative at x0= %lf is:\n%lf\n",x0,NumDerivative1(J,h,y,0));
    system("pause");
    return 0;
}

void gridDef(double X[],double X0,double H,int n)
{
    int i;
    for(i=0;i<n;++i)
        X[i]=X0+(i*H);
}

void funcDef(double Y[],double X[])
{
    int i;
    for(i=0;i<N;++i)
        Y[i]=X[i]*X[i];//Modify function formula
}

double kDiff(int k, int n, double Y[])
{
    if(k<1)
        return ERROR;
    else if(k==1)
        return Y[n+1]-Y[n];
    else
        return kDiff(k-1,n+1,Y)-kDiff(k-1,n,Y);
}

double NumDerivative1(int J,double H,double Y[],int n)
{
   double fprim=0.0;
   int i;
   for(i=1;i<=J;++i)
        fprim+=pow(-1.0,i-1)*kDiff(i,0,Y)/i;
   fprim/=H;
   return fprim;
}
