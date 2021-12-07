#include <iostream>
#include <string>
using namespace std;
bool isLower (int h1, int h2, double m1, double m2)
{
    if (h1 == h2)
    {
        if (m1 < m2) return true;
        return false;
    }
    else if (h1 < h2) return true;
    return false;
}
int main ()
{
    int n, i, h_beg, h_end, p, res;
    double m_beg, m_end;
    string g1, g2, m1, m2;
    cin >> n;
    while (n--)
    {
        res = 0;
        cin >> g1 >> g2;
        h_beg = (((g1[0] - '0') * 10) + (g1[1] - '0'));
        m_beg = (((g1[3] - '0') * 10) + (g1[4] - '0'));
        h_end = (((g2[0] - '0') * 10) + (g2[1] - '0'));
        m_end = (((g2[3] - '0') * 10) + (g2[4] - '0'));

        p = h_end - h_beg + 1;
        double* m_tab = new double [p];
        int* h_tab = new int [p];
        for (i = 0; i < p; i++)
        {
            h_tab[i] = i + h_beg;
        }

        for (i = 0; i < p; i++)
        {
            m_tab[i] = ((60 * (h_tab[i] % 12)) / 11.0);
            if (m_tab[i] != 60 && isLower(h_beg, h_tab[i], m_beg, m_tab[i]) == true && isLower(h_tab[i], h_end, m_tab[i], m_end) == true)
            {
                res++;
            }
        }
        if (h_tab[p - 1] == h_end && m_tab[p - 1] == m_end)
        {
            res++;
        }
        cout << res << "\n";
        delete [] m_tab;
        delete [] h_tab;
    }



return 0;
}
