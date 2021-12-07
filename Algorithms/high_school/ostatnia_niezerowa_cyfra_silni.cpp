#include <iostream>
using namespace std;
long long silnia(int a)
{
	long long silnia= 1;
	int i=1;
	while (i<=a)
	{
		silnia*=i;
		i++;
	}
	while(silnia%10==0) 
	{
		silnia=silnia/10;
	}
	return silnia%10;
}
int main ()
{
	int n, a;
	cin>>n;
	while(n--)
	{
	cin>>a;
	cout<<silnia(a)<<"\n";		
	}
	
	return 0;
}
