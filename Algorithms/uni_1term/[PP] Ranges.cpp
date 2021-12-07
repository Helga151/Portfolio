#include <iostream>
#include <algorithm>
using namespace std;
bool sorting_via_columns(int* a, int* b)
{
    int i = 0;
    while(a[i] == b[i] && i < 2)
    {
        i++;
    }
    if (a[i] < b[i]) return true;
    return false;
}
int main ()
{
    int t, n, i, j, pointer;
    long long solution;
    cin >> t;
    while (t--)
    {
        solution = 0;
        cin >> n;
        int** tab = new int* [n];
        for(i = 0; i < n; i++)
        {
            tab[i] = new int [2];
            for(j = 0; j < 2; j++)
            {
                cin >> tab[i][j];
            }
        }
        sort(tab, tab + n, sorting_via_columns);

        /*for (i = 0; i < n; i++)
        {
            for (j = 0; j < 2; j++)
            {
               cout << tab[i][j] << " ";
            }
            cout << "\n";
        }*/

        pointer = tab[0][0] - 1;

        for(i = 0; i < n; i++)
        {
            if(tab[i][0] > pointer) //wchodze do nowego przedzialu
            {
                pointer = tab[i][1];
                solution += tab[i][1] - tab[i][0] + 1; //ktorego dlugosc jest rowna koniec - poczatek + 1
                cout << pointer << " " << solution << "\n";
            }
            if(tab[i][1] > pointer) //jestem dalej w przedziale, ktory ma poczatek w tym samym punkcie, ale zwiekszam indeks konca
            {
                solution += tab[i][1] - pointer; //dodaje do wyniku dlugosc dolozonego zakresu
                pointer = tab[i][1];
                cout << pointer << " * " << solution << "\n";
            }
        }
        cout << solution << "\n";
        for (i = 0; i < n; i++)
        {
            delete [] tab[i];
        }
        delete [] tab;
    }

return 0;
}
