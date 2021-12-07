#include <iostream>
using namespace std;
bool prime (int a)
{
    int i;
    if (a < 2)
    {
        return false;
    }
    for (i = 2; i * i <= a; i++)
    {
        if (a % i == 0)
        {
            return false;
        }
    }
    return true;
}
int main ()
{
    int n, a;
    cin >> n;
    while (n--)
    {
        cin >> a;
        if(prime(a) == true)
        {
            cout << "TAK\n";
        }
        else
        {
            cout << "NIE\n";
        }
    }

return 0;
}
