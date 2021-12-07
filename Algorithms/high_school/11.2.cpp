#include <iostream>
using namespace std;

long long modul(long long n, long long k)
{
	long long pot=1;
	for(int i=1;i<=k;i++)
	{
		pot*=n;
	}
	return pot;
}
int main ()
{
	int n,k;
	cin>>n>>k; 
	cout<<modul(n,k);
	
return 0;
}
