#include <iostream>
#include <algorithm>
using namespace std;
int main ()
{
    long long t, n, i, zm, o, d;
    cin >> t;
    while (t--)
    {
        cin >> n;
        long long* tab = new long long [n];
        zm = o = d = 0;
        for (i = 0; i < n; i++)
        {
            cin >> tab[i];
            if (tab[i] > 2)
            {
                zm++;
            }
            else if (tab[i] == 1)
            {
                o++; //one
            }
            else if (tab[i] == 2)
            {
                d++; //two
            }
        }
        sort(tab, tab + n);
        if (zm == n)
        {
            //reverse
            for (i = n - 1; i >= 0; i--)
            {
                cout << tab[i] << " ";
            }
        }
        else
        {
            if (zm != d)
            {
                for (i = 0; i < o; i++)
                {
                    cout << tab[i] << " ";
                }
                for (i = n - 1; i >= o; i--)
                {
                    cout << tab[i] << " ";
                }
            }
            else
            {
                for (i = 0; i < (o + d); i++)
                {
                    cout << tab[i] << " ";
                }
                for (i = n - 1; i >= (o + d); i--)
                {
                    cout << tab[i] << " ";
                }
            }
        }
        cout << "\n";
        delete [] tab;
    }

return 0;
}
