
#include <iostream>

using namespace std;
int main ()
{
	int n, x, zm, p;
	double row;
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
			row = x - 1;
			row /= 5;
			if (row != int(row))
			{
				row = int(row) + 1;
			}
			cout << int (row);

			p = x; //seat_position
			if (p > 6)
			{
				zm = (row - 1) * 5; //zmienna - variable
				p -= zm;
			}
				if(p == 2 || p == 6)
				{
					cout << " W ";
				}
				else if(p == 4)
				{
					cout << " A ";
				}
				else //and another check for 3 and 5
				{
					if (int(row)% 2 == 0) //even number
					{
						if (p == 3)
						{
							cout << " M ";
						}
						else
						{
							cout << " A ";
						}
					}
					else // odd one
					{
						if (p == 5)
						{
							cout << " M ";
						}
						else
						{
							cout << " A ";
						}
					}
				}

					if (int(row) % 2 == 0)
					{
						if(p == 6 || p == 5)
						{
							cout << "L\n";
						}
						else
						{
							cout << "R\n";
						}
					}
					else
					{
						if(p == 2 || p == 3)
						{
							cout << "L\n";
						}
						else
						{
							cout << "R\n";
						}
					}


		}
	}
	return 0;
}
