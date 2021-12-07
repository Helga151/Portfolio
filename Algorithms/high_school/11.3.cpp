#include <iostream>
using namespace std;

long long silnia (long long s)
{
	long long silnia=1;
	int i=1;
	for(i=1;i<=s;i++)
	{
		silnia*=i;
	}
	return silnia;
}

int main()
{
	int s;
	cin>>s;
	cout<<silnia(s);
	
	return 0;
}
