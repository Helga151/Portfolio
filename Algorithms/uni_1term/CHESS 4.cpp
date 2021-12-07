#include <iostream>
using namespace std;
int main ()
{
    int t, n, m;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        if ((n % 2 == 0 && m % 2 == 0) || (n % 2 == 1 && m % 2 == 1)) //both are even or odd
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
    }

return 0;
}
