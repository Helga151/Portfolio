#include <iostream>
using namespace std;
double wart(double x)
{
	if(x>=0) return x;
	return -x;
}
int main ()
{
	double x;
	cin>>x;
	cout.setf(ios::fixed, ios::floatfield);
	cout.precision(2);
	cout<<wart(x);
	
	return 0;
}
