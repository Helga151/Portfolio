#include <iostream>
using namespace std;

long long tab[50000];

int main ()
{
    long long n, i, m, x, y, sum, maxi, q;

    cin >> n;
    for(i = 1; i <= n; i++)
    {
        cin >> tab[i];
    }
    cin >> m;
    while(m--)
    {
        cin >> q >> x >> y;

        if(q == 1)
        {
            maxi = tab[x];
            sum = 0;
            for(i = x; i <= y; i++)
            {
                if(sum + tab[i] >= tab[i])
                {
                    sum += tab[i];
                    //cout << "1. " << sum << " " << tab[i] << "\n";
                }

                else
                {
                    sum = tab[i];
                }
                maxi = max(maxi, sum);
                //cout << "2. " << maxi << "\n";
            }

            cout << maxi << "\n";
        }

        else
        {
            tab[x] = y;
        }

    }



return 0;
}
