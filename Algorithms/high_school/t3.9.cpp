#include <iostream>
using namespace std;
int main ()
{
	double n;
	cin>>n;
	cout.setf(ios::fixed, ios::floatfield);
	cout.precision(4);
	cout<<n/(57.29578);
	
	return 0;
}
