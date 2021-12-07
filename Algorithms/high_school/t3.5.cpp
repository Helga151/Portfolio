#include <iostream>
using namespace std;
int main ()
{
	int a,b,c;
	cin>>a>>b;
	c=a-b;
	if(c<0) c=-c;
	cout<<(a+b-c)/2;
	
	return 0;
}
