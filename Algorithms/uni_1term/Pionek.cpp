#include <iostream>
using namespace std;
int tab [1000001];
int maxi(int* tab, int pointer)
{
    int i;
    int m = -1000000000;
    for(i = 0; i < 6; i++)
    {
        m = max(tab[pointer - i - 1], m);
    }
    return m;
}
int main ()
{
    int n, i, sum = 0, a, m, j;
    cin >> n;
    cin >> tab[1];
    for (i = 2; i <= n; i++)
    {
        cin >> a;
        int m = -1000000000;
        if(i > 6)
        {
            tab[i] = a + maxi(tab, i);
        }
        else
        {
            for(j = 1; j < i; j++)
            {
                m = max(tab[j], m);
            }
            tab[i] = a + m;
        }
    }
    cout << tab[n];

return 0;
}
