#include <iostream>
using namespace std;
int main()
{
	int wys, i, j, a=0, b;
	cin>>wys;
	
	cout<<"X"<<endl;
	
	for(j=0; j<(wys-1); j++)
	{
		cout<<"X";
		for(i=0; i<=(a-2); i++)
		{
		cout<<" ";
		}
		cout<<"X"<<endl;
		a++;
	}
	
	for (b=0; b < wys; b++)
	{
		cout<<"X";
	}
	
	return 0;
}
