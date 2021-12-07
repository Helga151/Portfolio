#include <iostream>
#include <math.h>
using namespace std;
int main ()
{
	double a,b,c,p,r;
	cin>>a>>b>>c;
	cout.setf(ios::fixed, ios::floatfield);
	cout.precision(2);
	p=(a+b+c)/2;
	r=(p*(p-a)*(p-b)*(p-c));
	cout<<"Pole trojkata: " <<sqrt(r);
	
	return 0;
}
