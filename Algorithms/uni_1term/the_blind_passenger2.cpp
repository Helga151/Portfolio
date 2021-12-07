
#include <iostream>

using namespace std;
int main ()
{
	int n, x, p, i;
	double zm;
	cin >> n;
	while(n--)
	{
		cin >> x;
		if (x == 1)
		{
			cout << "poor conductor\n";
		}
		else
		{
			zm = x;
			zm = (zm - 1) / 5;
			if (zm != int(zm))
			{
				zm = int(zm) + 1;
			}
			cout << zm << "\n";
			for (i = 2; i <= x; i++)
			{
				cout << i << " ";
			}
		}
	}
	
	return 0;
}
