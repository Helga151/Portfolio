#include <iostream>
#include <algorithm>
using namespace std;
int main ()
{
    int n, i, a;
    cin >> n;
    while (n --)
    {
        cin >> a;
        int* tab = new int [a];
        for (i = 0; i < a; i++)
        {
            cin >> tab[i];
        }
        reverse(tab, tab + a);
        for (i = 0; i < a; i++)
        {
            cout << tab[i] << " ";
        }
        cout << "\n";
    }

return 0;
}
