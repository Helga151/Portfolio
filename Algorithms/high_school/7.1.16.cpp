#include <iostream>
using namespace std;
int main()
{
	int h, a=1;
	cin>>h;
	
	for(int i=0; i<h; i++)
	{
		for(int j=1; j<=a; j++)
		{
			cout<<j*a<<" ";
		}
		cout<<endl;
		a++;
	}
	
	return 0;
}
