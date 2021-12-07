#include <iostream>

using namespace std;

int main ()
{
	int wys, szer;
	cin>>szer>>wys;
	
	for(int j=1; j<=wys; j++)
	{
		for(int i=1; i<=szer; i++)
		{
			cout<<"X";
			if(i==szer)
			cout<<endl;;
		}
	}
	
	
	return 0;
}
