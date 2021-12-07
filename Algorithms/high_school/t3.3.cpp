#include <iostream>
using namespace std;
int main ()
{
	double d,n,k;
	cin>>d>>n>>k;
	cout.setf(ios::fixed, ios::floatfield);
	cout.precision(2);
	cout<<(n*k)*(d/100)<<" zl";	
	
	return 0;
}
