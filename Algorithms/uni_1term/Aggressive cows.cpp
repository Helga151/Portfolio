#include <iostream>
#include <algorithm>
using namespace std;

int cow_in_row (int tab[], int n, int mid, int c) //how many cows can we have
{
    int i, var = 1, where = 1; //var - counting cows, where - where have i put the last cow
    for (i = 2; i <= n; i++)
    {
        if (tab[i] - tab[where] >= mid)
        {
            var ++;
            where = i;
        }
        if (var >= c)
        {
            return var;
        }
    }
    return 0; //we cant assign cows

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, c, i, h, mid, e, b, x;
    cin >> t;
    while (t--)
    {
        cin >> n >> c;
        int * tab = new int [n + 1];
        for (i = 1; i <= n; i++)
        {
            cin >> tab[i];
        }
        sort (tab + 1,  tab + n + 1);
        b = 1; //begin
        e = tab [n] - tab [1]; //end

        while (b < e)
        {
        mid = (b + e + 1) / 2;
        cout << mid << " ";
        x = cow_in_row(tab, n, mid, c);
        cout << x << "\n";
        if (x >= c) b = mid;
        else e = mid - 1;
        }
        cout << b << "\n";
        delete [] tab;
    }
    return 0;
}
