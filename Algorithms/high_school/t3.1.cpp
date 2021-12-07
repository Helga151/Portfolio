#include <iostream>
using namespace std;
int main ()
{
	double a, b, h;
	cin>>a>>b>>h;
	cout.setf(ios::fixed, ios::floatfield);
	cout.precision(2);
	cout<<((a+b)*h)/2;
	return 0;
}
