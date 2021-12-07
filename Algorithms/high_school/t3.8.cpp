#include <iostream>
#include <math.h>
using namespace std;
int main ()
{
	double x,y,h;
	cin>>x>>y;
	cout.setf(ios::fixed, ios::floatfield);
	cout.precision(2);
	h=sqrt(x*y);
	cout<<((x+y)*h)/2;
	
	return 0;
}
