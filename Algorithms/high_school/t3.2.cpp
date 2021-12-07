#include <iostream>
using namespace std;
int main ()
{
	double a;
	cin>>a;
	cout.setf(ios::fixed, ios::floatfield);
	cout.precision(2);
	cout<<(3*a+2)/(3*a);
	
	return 0;
}
