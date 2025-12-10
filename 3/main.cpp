#include <iostream>
#include <math.h>

using namespace std;

typedef long double real;
typedef unsigned long int natural;


int main(int argc, char* argv[])
{

	real a11=0.39242327;
	real a12=0.48373288;
	real a21=0.54732143;
	real a22=0.41034483;
	
	real p1=(a22-a21)/(a11+a22-a12-a21);
	real p2=1-p1;
	real q1=(a22-a12)/(a11+a22-a12-a21);
	real q2=1-q1;
	cout.precision(8); // <- выводим N знаков после запятой
	cout<<"p1="<<p1<<" p2="<<p2<<" q1="<<q1<<" q2="<<q2<<endl;
	
	cout<<"v1="<<a11*p1+a21*p2<<" v2="<<a12*p1+a22*p2<<endl;

	cout<<"v1="<<a11*q1+a12*q2<<" v2="<<a21*q1+a22*q2<<endl;
	
	return 0;
}
