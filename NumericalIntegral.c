/* This is a programing template for numerical evaluation of an integral of a
certain function at a particular interval. Just write the function formula in
the variable y[i], put the initial values for a,b (interval of integration), N(elements of the grid),
compile it and get your results.*/
/* This is an open Source Code,
 Redistribute it as you wish,
 Creator: tdepastas, 2018
 */
#include <stdio.h>
#include <math.h>
#define ERROR -1

int N=10;//Modify grid elements and accuracy
double a=1.0,b=3.0;//Modify interval size
double x[],y[];

double NumIntegral(double *,double ,double ,int );
void funcDef(int ,double *,double *),gridDef(double *,double ,double ,int );


int main()
{
    int i;
    printf("X's Grid:\n");
    gridDef(x,a,(b-a)/N,N);
    for(i=0;i<=N;++i)
        printf("%lf,",x[i]);
    printf("\nFunction Grid:\n");
    funcDef(N,y,x);
    for(i=0;i<=N;++i)
        printf("%lf,",y[i]);
    printf("\nDefinite Integral from a= %lf to b=%lf is:\n%lf\n",a,b,NumIntegral(y,a,b,N));
    system("pause");
    return 0;
}

void gridDef(double X[],double X0,double H,int n)
{
    int i;
    for(i=0;i<=n;++i)
        X[i]=X0+(i*H);
}

void funcDef(int n,double Y[],double X[])
{
    int i;
    for(i=0;i<=n;++i)
        Y[i]=2*X[i];//Modify function formula
}

double NumIntegral(double Y[],double A,double B,int n)
{
    double Intf=0.0,H;
    int i;
    H=(B-A)/n;
    for(i=1;i<=N-1;++i)
        Intf+=Y[i];
    Intf*=2;
    Intf+=Y[0]+Y[N];
    Intf*=H/2;
    return Intf;
}
