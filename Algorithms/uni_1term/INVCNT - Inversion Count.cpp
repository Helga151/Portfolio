#include <iostream>
using namespace std;
long long merge(long long tab[], long long arr[], long long l, long long m, long long r)
{
    long long i = l, j = m + 1, k = l, inv_m = 0;

    while ((i <= m) && (j <= r))
    {
        if (tab[i] > tab[j])
        {
            arr[k] = tab[j];
            j++;
            inv_m += (m - i + 1);
        }
        else
        {
            arr[k] = tab[i];
            i++;
        }
        k++;
    }

    while (i <= m)
    {
        arr[k] = tab[i];
        k++;
        i++;
    }
    while (j <= r)
    {
        arr[k] = tab[j];
        k++;
        j++;
    }

    for (i = l; i <= r; i++)
    {
        tab[i] = arr[i];
    }

    return inv_m;
}
long long mergeSort (long long tab[], long long arr[], long long l, long long r)//l - left, r -right
{
    long long m, inv = 0; //m - mid
    if (r > l)
    {
        m = (l + r) / 2;
        inv += mergeSort(tab, arr, l, m);
        inv += mergeSort(tab, arr, m + 1, r);
        inv += merge(tab, arr, l, m, r);
    }
    return inv;
}

int main ()
{
    long long n, t, i, p;
    cin >> n;
    while (n--)
    {
        cin >> t;
        long long* tab = new long long[t];
        long long* arr = new long long[t];
        for (i = 0; i < t; i++)
        {
            cin >> tab[i];
        }
        cout << mergeSort(tab, arr, 0, t - 1) << "\n";

        delete [] tab;
        delete [] arr;
    }

return 0;
}
