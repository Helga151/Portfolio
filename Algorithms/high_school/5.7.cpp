#include <iostream>
using namespace std;
int main()
{
	int n, a=1, b=2, c=3;
	cin>>n;
	
	for(int i=1; i<=n; i++)
	{
	   if(a*a+b*b==c*c || a*a+c*c==b*b || b*b+c*c==a*a)
	   {
	   	cout<<a<<" "<<b<<" "<<c<<endl;
	   	a++;
	   	b++;
	   	c++;
	   }
	   else
	   {
	   	a++;
	   	b++;
	   	c++;
	   }
	}
	
	return 0;
}
