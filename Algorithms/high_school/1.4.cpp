#include <iostream>
using namespace std;
int main ()
{
	double a, b;
	cin>>a>>b;
	cout.setf(ios::fixed, ios::floatfield);	
	cout.precision(3);
	cout<<a+b;
	return 0;
}
