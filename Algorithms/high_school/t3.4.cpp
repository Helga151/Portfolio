#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	double h,a;
	cin>>h;
	cout.setf(ios::fixed, ios::floatfield);
	cout.precision(2);
	a=(2*h)/sqrt(3);
	cout<<((a*a)*sqrt(3))/4;
	
	return 0;
}
