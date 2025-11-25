#include <iostream>
#include <math.h>

using namespace std;

typedef long double real;
typedef unsigned long int natural;

real fact(const natural n) // да, факториал - натуральное число, но происходит потеря точности при больших n для unsigned long int, поэтому long double
{
	if(n==0)
		return 1;
	else
		return n*fact(n-1);
}

real sum(const real alpha,const natural n);

real p(const real alpha,const natural n)
{
	return (powl(alpha,n)/fact(n))/sum(alpha,n);
}

real sum(const real alpha,const natural n)
{
	if(n==0)
		return powl(alpha,n)/fact(n); // const=1
	else
		return powl(alpha,n)/fact(n)+sum(alpha,n-1);
}

int main(int argc, char* argv[])
{
	real mu=0.3;
	real a[][3] = // <- 3 rows
		{ 
		    {0.4,0.3,0.3},
		    {0.3,0.4,0.3},
		    {0.4,0.4,0.2}
		};

    natural b[][3] = // <- 3 rows
		{    
		    {3,1,0},
		    {2,2,0},
		    {1,2,1}
		};

    //a [row] [col]

	std::cout.precision(8); // <- выводим N знаков после запятой

	real pn=0;
	for(natural i=0;i<sizeof a/sizeof a[0];i++,cout<<endl) // rows
		for(natural j=0;j<sizeof a[0]/sizeof(a[0][0]);j++,cout<<pn<<"\t",pn=0) // cols
			for(natural k=0;k<sizeof a[0]/sizeof(a[0][0]);k++) // cols
				pn+=a[i][k]*p(a[i][k]/mu,b[j][k]);

	return 0;
}
