#include <iostream>

using namespace std;

int main()
{
	int w, k;
	cin>>w>>k;
	
    for(int j=1; j<=w; j++)
    {
	   for(int i=1; i<=k; i++)
	   {
		  cout<<i*j<<" ";
		  if(i==k)
		  {
		  	cout<<endl;
		  }
	   }
    }
	return 0;
}
