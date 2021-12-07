#include <iostream>
#include <algorithm>
using namespace std;
bool sorting_via_columns (int* a, int* b) //wskazniki na adresy wierszy, a nie na komorki, dlatego daje a[i]
{
    int i = 0;
    while((a[i] == b[i]) && (i < 3)) //sprawdzam do momentu az trafie na komórke która sie rózni
    {
       i++;
    }
    if (a[i] < b[i]) return true;
    return false;
}
int main ()
{
    int t, i, j, a;
    cin >> t;
    int** tab = new int* [t];
    for (i = 0; i < t; i++)//tworzenie tablicy 2D
    {
        tab[i] = new int [3];
        for (j = 0; j < 3; j++)
        {
            cin >> a;
            tab[i][j] = a;
        }
    }
    sort(tab, tab + t, sorting_via_columns); //nie podaje argumentów do funkcji sortujacej, bo ona sama sobie dobiera wartosci

    for (i = 0; i < t; i++)
    {
        for (j = 0; j < 3; j++)
        {
           cout << tab[i][j] << " ";
        }
        cout << "\n";
    }

    for (i = 0; i < t; i++) //usuwanie tablicy 2D
    {
        delete [] tab[i];
    }
    delete [] tab;
/*
bool sorting_via_columns(int* a, int* b)
{
    int i = 0;
    while((a[i] == b[i]) && i < 3)
    {
        i++;
    }
    if(a[i] < b[i]) return true;
    return false;
}
int main()
{
    int t, i, j;
    cin >> t;
    int** tab = new int*[t];
    for(i = 0; i < t; i++)
    {
        tab[i] = new int[3];
        for(j = 0; j < 3; j++)
        {
            cin >> tab[i][j];
        }
    }
    sort(tab, tab + t, sorting_via_columns);
    for(i = 0; i < t; i++)
    {
        for(j = 0; j < 3; j++)
        {
            cout << tab[i][j] << " ";
        }
        cout << "\n";
    }

    for(i = 0; i < t; i++)
    {
        delete [] tab[i];
    }
    delete [] tab;
*/
return 0;
}
